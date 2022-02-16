/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:11:54 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:11:55 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"

/*
 * Prints the copyright notice. If a real tty is used, colours are used.
 */
static void	print_header_part3(void)
{
	if (isatty(1))
		write(1, "\nMade by \033[1;31mnimichi\033[1;0m (github.com/nimichi) and "
			"\033[1;32mmhahnFr\033[1;0m (github.com/mhahnFr).\n\n", 99);
	else
		write(1, "\nMade by nimichi (github.com/nimichi) and "
			"mhahnFr (github.com/mhahnFr).\n\n", 73);
}

/*
 * Prints the downer half of the 42 ASCII art.
 */
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

void	print_header(void)
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
