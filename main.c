#include <stdio.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "command.h"

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
	write(1, "\nMade by nimichi (github.com/nimichi) and mhahn"
		"Fr (github.com/mhahnFr).\n", 72);
}

static void	print_header(void)
{
	write(1, "                /####/  #################       "
		"                               \n", 80);
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

int	main(
		__attribute__((unused)) int argc,
		__attribute__((unused)) char **args,
		__attribute__((unused)) char **envp)
{
	char	*line;

	print_header();
	while (true)
	{
		line = readline("");
		//parse(line, cmd, envp);
		if (line == NULL)
			break ;
		free(line);
	}
	free(line);
	return (0);
}
