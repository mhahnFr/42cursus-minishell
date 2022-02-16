/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:01:03 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/16 17:29:07 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "token.h"
#include "tokenizer.h"
#include "utils.h"

int	pipe_skip_qtm_and_move(char *str)
{
	int		i;

	i = 1;
	if (str[0] == '"' || str[0] == '\'')
		while (str[i] != str[0])
			i++;
	if (str[0] == '"' || str[0] == '\'')
		i++;
	return (i);
}

int	pipe_check(t_token *token)
{
	int		i;
	int		prthcnt;

	i = 0;
	prthcnt = 0;
	while (i < token->strlen)
	{
		if ((token->str)[i] == '|')
			return (i);
		while ((token->str)[i] == '(' || prthcnt != 0)
		{
			if ((token->str)[i] == '(')
				prthcnt++;
			else if ((token->str)[i] == ')')
				prthcnt--;
			i = i + pipe_skip_qtm_and_move(&(token->str)[i]);
		}
		i = i + pipe_skip_qtm_and_move(&(token->str)[i]);
	}
	return (0);
}

void	pipe_split_heredoc(t_token *token, int childno, int len)
{
	int			i;
	int			j;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	i = 0;
	while (token->str[i] != '\0')
	{
		j = i;
		if (token->str[i] == '\'' || token->str[i] == '"')
		{
			while (token->str[i + 1] != token->str[j])
				i++;
			i = i + 2;
		}
		if (token->str[i] == '<' && token->str[i + 1] == '<'
			&& ((i > len && childno == 0) || (i < len && childno == 1)))
			token_remove_heredoc(token, !childno);
		i++;
	}
}

pid_t	pipe_childs(int childno, t_token *token, int len, int pipe_fds[2])
{
	pid_t	child;

	child = fork();
	if (child != 0)
		return (child);
	pipe_split_heredoc(token, childno, len);
	if (childno == 0 && 0 == child)
	{
		token->strlen = len;
		token->str[token->strlen] = '\0';
		if (token->fdout != -1)
			close(token->fdout);
		token->fdout = pipe_fds[1];
	}
	else if (childno == 1 && 0 == child)
	{
		token->strlen = token->strlen - len - 1;
		token->str = &token->str[len + 1];
		token->str[token->strlen] = '\0';
		if (token->fdin != -1)
			close(token->fdin);
		token->fdin = pipe_fds[0];
	}
	close(pipe_fds[childno]);
	exit(tokenizer_func(token));
}

int	pipe_func(t_token *token)
{
	int		pipe_fds[2];
	int		len;
	pid_t	child1;
	pid_t	child2;

	len = pipe_check(token);
	if (pipe(pipe_fds) == -1)
		return (-1);
	child1 = pipe_childs(0, token, len, pipe_fds);
	if (child1 < 0)
		return (-1);
	child2 = pipe_childs(1, token, len, pipe_fds);
	if (child2 < 0)
		return (-1);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, &len, 0);
	if (WIFEXITED(len))
		token->exitstat = WEXITSTATUS(len);
	else
		token->exitstat = 1;
	while (token->strlen != 0)
		token_move_one_char(token);
	return (tokenizer_func(token));
}
