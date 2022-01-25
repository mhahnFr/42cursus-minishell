#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "minishell.h"
#include "command.h"
#include "signals.h"
#include "syntax.h"
#include "tokenizer.h"
#include "utils.h"

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
	write(1, "\nMade by \033[1;31mnimichi\033[1;0m (github.com/nimichi) and "
		"\033[1;32mmhahnFr\033[1;0m (github.com/mhahnFr).\n\n", 99);
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
	char			*line;
	struct s_token	*tokens;

	print_header();
	while (true)
	{
		signals_default();
		line = readline(PROMPT " ");
		if (line == NULL)
			break ; // TODO Call the exit builtin
		if (!utils_only_whitespace(line))
		{
			add_history(line);
			if (syntax_check(line) == 0)
			{
				//parse(line, cmd, envp);
				tokens = tokenize(line);
				if (tokens != NULL)
				{
					//execute(tokens);
				}
			}
		}
		free(line);
	}
	return (0);
}
