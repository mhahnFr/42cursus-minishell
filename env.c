/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:08 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 21:43:56 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "env.h"

int	builtin_env(char **argv, char **env)
{
	size_t	index;
	size_t	j;

	if (argv[1] != NULL)
	{
		ft_putendl_fd("Too many arguments!\n", 2);
		return (1);
	}
	index = 0;
	while (env[index] != NULL)
	{	
		j = 0;
		while (env[index][j] != '=' && env[index][j] != '\0')
			j++;
		if (env[index][j] == '=')
			printf("%s\n", env[index]);
		index++;
	}
	return (0);
}

char	*get_envar(char **env, char *str, int *slen, char mode)
{
	int	j;

	while (env != NULL && *env != NULL)
	{
		j = 0;
		while ((*env)[j] == str[j + 1] && j < *slen - 1)
			j++;
		if ((*env)[j] == '=' && j == *slen - 1)
		{
			if (mode != '"')
				while ((*env)[j + 1] == ' ' && (*env)[j + 2] == ' ')
					j++;
			*slen = 0;
			while ((*env)[j + 1 + *slen] != '\0')
				(*slen)++;
			if (mode != '"')
				while ((*env)[j + *slen] == ' ' && (*env)[j + *slen - 1] == ' '
					&& *slen > 1)
					(*slen)--;
			return (&env[0][j + 1]);
		}
		env++;
	}
	*slen = 0;
	return (NULL);
}
