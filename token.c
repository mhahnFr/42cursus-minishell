/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:37:35 by mnies             #+#    #+#             */
/*   Updated: 2022/02/15 20:16:36 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"

#include "signals.h"
#include "token.h"
#include "unistd.h"

int	token_check_eof(char *line, char *str)
{
	int	i;

	i = 0;
	while (*str == ' ')
		str++;
	while (line[i] == *str && line[i] != '\0' && *str != ' ' && *str != '|'
		&& *str != ')' && *str != '&')
	{
		i++;
		str++;
	}
	if (line[i] == '\0' && (*str == ' ' || *str == '|' || *str == ')'
			|| *str == '&' || *str == '\0'))
	{
		free(line);
		return (1);
	}
	return (0);
}

t_heredoc	*token_get_heredocs(char *str)
{
	t_heredoc		*heredoc;
	char			*line;
	int				pint[2];

	while (str[0] != '\0' && !(str[0] == '<' && str[1] == '<'))
		str++;
	if (str[0] == '\0')
		return (NULL);
	heredoc = malloc(sizeof(t_heredoc));
	if (heredoc == NULL || pipe(pint) == -1)
		exit(1);
	signals_default();
	line = readline(">" " ");
	heredoc->fd = pint[0];
	while (line != NULL && !token_check_eof(line, &str[2]))
	{	
		write(pint[1], line, ft_strlen(line));
		write(pint[1], "\n", 1);
		free(line);
		line = readline(">" " ");
	}
	close(pint[1]);
	signals_execution();
	heredoc->next = token_get_heredocs(&str[2]);
	return (heredoc);
}

void	token_remove_heredoc(t_token *token, int i)
{
	t_heredoc	*temp;
	t_heredoc	*temp2;

	if (i == 0)
	{
		temp = token->heredoc->next;
		close(token->heredoc->fd);
		free(token->heredoc);
		token->heredoc = temp;
		return ;
	}
	temp = NULL;
	temp2 = token->heredoc;
	while (temp2->next != NULL)
	{
		temp = temp2;
		temp2 = temp2->next;
	}
	close(temp2->fd);
	free(temp2);
	if (temp != NULL)
		temp->next = NULL;
}

void	token_move_one_char(t_token *token)
{
	token->str = &token->str[1];
	token->strlen = token->strlen - 1;
}
