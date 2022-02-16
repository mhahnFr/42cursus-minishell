/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:25 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/16 02:46:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "get_next_line.h"

#include "exit.h"
#include "utils.h"

/*
 * Returns wether the given string contains only digits. It may be preceeded by
 * a plus or minus sign.
 */
static bool	ft_isnum(char *string)
{
	size_t	i;

	i = 0;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i] != '\0')
	{
		if (string[i] < '0' || string[i] > '9')
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}

int	builtin_exit(char **argv, t_token *token)
{
	if (argv != NULL && argv[1] != NULL)
	{
		if (!ft_isnum(argv[1]))
		{
			ft_putendl_fd("exit: Numeric argument required!", 2);
			token->exitstat = 255;
		}
		else if (argv[2] != NULL)
		{
			ft_putendl_fd("exit: Too many arguments!", 2);
			token->exitstat = 1;
			return (1);
		}
		else
			token->exitstat = ft_atoi(argv[1]);
	}
	exit(utils_free_token(token, 2));
	return (0);
}
