/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:43 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:12 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"
#include "libft/libft.h"

#include "exit.h"
#include "minishell.h"
#include "signals.h"
#include "syntax.h"
#include "tokenizer.h"
#include "utils.h"

static char	*main_readline(void)
{
	char	*line;

	if (isatty(0))
		line = readline(PROMPT " ");
	else
	{
		line = get_next_line(0);
		if (line != NULL)
			line[ft_strlen(line) - 1] = '\0';
	}
	return (line);
}

int	main(void)
{
	t_token	token;
	char	*line;

	if (isatty(0))
		print_header();
	token_create(&token);
	while (true)
	{
		signals_default();
		line = main_readline();
		if (line == NULL)
		{
			line = "exit";
			if (isatty(0))
				printf("exit\n");
		}
		if (!utils_only_whitespace(line))
		{
			add_history(line);
			if (syntax_check(line) == 0)
			{
				token.strlen = ft_strlen(line);
				token.str = line;
				token.lptr = token.str;
				token.heredoc = token_get_heredocs(token.str);
				signals_execution();
				tokenizer_func(&token);
			}
			else
				token.exitstat = 2;
		}
	}
	return (0);
}
