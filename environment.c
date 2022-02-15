/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:14 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:26 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "utils.h"

size_t	get_env_size(const char **env)
{
	size_t	size;

	size = 0;
	while (env[size] != NULL)
		size++;
	return (size);
}

char	**copy_env(void)
{
	char		**ret;
	size_t		index;
	extern char	**environ;

	ret = malloc((get_env_size((const char **) environ) + 1) * sizeof(char *));
	if (ret == NULL)
	{
		ft_putendl_fd("Malloc failed while copying the environment!", 2);
		return (NULL);
	}
	index = 0;
	while (environ[index] != NULL)
	{
		ret[index] = ft_strdup(environ[index]);
		index++;
	}
	ret[index] = NULL;
	return (ret);
}
