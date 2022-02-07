/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:35:11 by mnies             #+#    #+#             */
/*   Updated: 2022/02/07 15:00:48 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "pipe.h"
#include "parse.h"
#include "libft.h"

int	tokenizer_check_or_and(t_token *token)
{
	int		i;
	int		p_cnt;
	char	c;

	i = 0;
	p_cnt = 0;
	while (i < token->strlen || (token->str[0] != '\0' && token->strlen == 0))
	{
		c = token->str[i];
		if (c == '(')
			p_cnt++;
		else if (c == ')')
			p_cnt--;
		else if (c == '\'' || c == '"')
			while (token->str[i + 1] != c)
				i++;
		else if ((c == '&' || c == '|') && token->str[i + 1] == c && p_cnt == 0)
			return (i + 1);
		i++;
	}
	return (0);
}

int	tokenizer_apply_parenthesis(t_token *token)
{
	pid_t	child;
	int		status;

	child = fork();
	if (child < 0)
		return (-1); // TODO FREE TOKEN
	if (0 == child)
	{
		while (token->str[token->strlen] != ')')
			token->strlen--;
		token->str[token->strlen] = '\0';
		exit(tokenizer_func(token));
	}
	token->str = &token->str[token->strlen];
	token->strlen = 0;
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		token->exitstat = WEXITSTATUS(status);
	else
		token->exitstat = -1;
	return (token->exitstat);
}

int	tokenizer_apply_or_and(t_token *token)
{
	int	pos;

	pos = tokenizer_check_or_and(token);
	if (pos == 1 && ((token->exitstat != 0 && token->str[0] == '|')
			|| (token->exitstat == 0 && token->str[0] == '&')))
	{
		token->str = &token->str[2];
		token->strlen = ft_strlen(token->str);
		return (tokenizer_func(token));
	}
	else if (pos == 1)
	{
		token->str = &token->str[2];
		token->strlen = ft_strlen(token->str);
		pos = tokenizer_check_or_and(token);
		if (0 == pos)
			return (token->exitstat);
		token->str = &token->str[pos + 1];
		return (tokenizer_func(token));
	}
	token->strlen = (pos - 1);
	return (tokenizer_func(token));
}

int	tokenizer_check_parenthesis(t_token *token)
{
	int		i;

	i = 0;
	while (token->str[i] == ' ')
		i++;
	if (token->str[i] == '(')
	{
		token->str = &token->str[i + 1];
		token->strlen = token->strlen - (i + 1);
		return (1);
	}
	return (0);
}

int	tokenizer_func(t_token *token)
{
	if (token->str[0] == '\0')
		return (token->exitstat);
	if (tokenizer_check_or_and(token))
		return (tokenizer_apply_or_and(token));
	else if (pipe_check(token))
		return (pipe_func(token));
	else if (tokenizer_check_parenthesis(token))
		return (tokenizer_apply_parenthesis(token));
	else
		return (parse_func(token));
}
