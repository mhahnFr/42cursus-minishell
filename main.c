#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft/libft.h"

#include "minishell.h"
#include "command.h"
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

	print_header();
	while (true)
	{
		signals_default();
		line = readline(PROMPT " ");
		//line = ft_strdup("hello|echj");
		if (line == NULL)
			break ; // TODO Call the exit builtin
		if (!utils_only_whitespace(line))
		{
			add_history(line);
			if (syntax_check(line) == 0)
			{
				token.strlen = ft_strlen(line);
				token.str = line;
				tokenizer_func(&token);
			}
		}
		free(line);
	}
	return (0);
}
