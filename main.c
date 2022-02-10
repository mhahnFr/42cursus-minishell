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

static void	print_header_part3(void)
{
	if (isatty(1))
		write(1, "\nMade by \033[1;31mnimichi\033[1;0m (github.com/nimichi) and "
			"\033[1;32mmhahnFr\033[1;0m (github.com/mhahnFr).\n\n", 99);
	else
		write(1, "\nMade by nimichi (github.com/nimichi) and "
			"mhahnFr (github.com/mhahnFr).\n\n", 73);
}

static void	print_header_part2(void)
{
	write(1, "#####################   ######       /###       "
		"                               \n", 80);
	write(1, "#####################   ######     /#####       "
		"                               \n", 80);
	write(1, "               ######   #################       "
		"                               \n", 80);
	write(1, "               ######                           "
		"                               \n", 80);
	write(1, "               ######                           "
		"                               \n", 80);
	write(1, "               ######   #                       "
		"                               \n", 80);
	write(1, "   _                    #  #  #  #==  #  #    #="
		"=\\   #==,  *==*  #\\\\  #  #\\\\  #\n", 80);
	write(1, "  |c| mhahnFr           #  #==#  #=   #  #    #="
		"=<   #=*   #  #  # \\\\ #  # \\\\ #\n", 80);
	write(1, "  '-'                   #  #  #  #==  #  #==  #="
		"=/   # \\\\  *==*  #  \\\\#  #  \\\\#\n", 80);
	write(1, "                        #                       "
		"                               \n", 80);
	print_header_part3();
}

static void	print_header(void)
{
	write(1, "\n                /####/  #################       "
		"                               \n", 81);
	write(1, "              /####/    #####/     ######       "
		"                               \n", 80);
	write(1, "            /####/      ###/       ######       "
		"                               \n", 80);
	write(1, "          /####/        #/         /####/       "
		"                               \n", 80);
	write(1, "        /####/          /        /####/         "
		"                               \n", 80);
	write(1, "      /####/                   /####/           "
		"                               \n", 80);
	write(1, "    /####/                   /####/             "
		"                               \n", 80);
	write(1, "  /####/                   /####/               "
		"                               \n", 80);
	write(1, "/####/                   /####/         /       "
		"                               \n", 80);
	write(1, "#####################   ######         /#       "
		"                               \n", 80);
	print_header_part2();
}

int	main(void)
{
	t_token	token;
	char	*line;

	token.c_args = NULL;
	if (isatty(0))
		print_header();
	token.envp = copy_env();
	token.exitstat = 0;
	while (true)
	{
		signals_default();
		if (isatty(0))
			line = readline(PROMPT " ");
		else
			line = get_next_line(0);
		if (line == NULL)
		{
			line = "exit";
			if (isatty(0))
				printf("exit\n");
		}
		int save_in, save_out;

		save_in = dup(STDIN_FILENO);
		save_out = dup(STDOUT_FILENO);
		if (!utils_only_whitespace(line))
		{
			add_history(line);
			if (syntax_check(line) == 0)
			{
				token.strlen = ft_strlen(line);
				token.str = line;
				token.lptr = token.str;
				signals_execution();
				tokenizer_func(&token);
			}
			else
				token.exitstat = 2;
		}
		dup2(save_in, STDIN_FILENO);
		dup2(save_out, STDOUT_FILENO);
	}
	utils_free_token(&token, 2);
	signals_reset_echoctl();
	return (0);
}
