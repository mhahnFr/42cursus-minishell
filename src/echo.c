/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:59:59 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:32 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include "echo.h"
#include "utils.h"

static bool	only_ns(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

int	builtin_echo(char **argv)
{
	bool	nl;
	bool	stop;
	size_t	i;

	nl = true;
	stop = false;
	i = 1;
	while (argv[i] != NULL)
	{
		if (string_starts_with(argv[i], "-n") && only_ns(&argv[i][1]) && !stop)
		{
			nl = false;
			i++;
			continue ;
		}
		stop = true;
		printf("%s", argv[i]);
		if (argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (nl)
		printf("\n");
	return (0);
}
