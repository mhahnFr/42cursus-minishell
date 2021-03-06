/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:30 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:20 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "env.h"
#include "export.h"
#include "token.h"
#include "utils.h"

/*
 * Adds the given variable to the environment. The given variable will be
 * appended, resulting in a newly allocated environment, using the given
 * length. The pointer in the token points to the new environment after
 * invocation.
 */
static void	builtin_export_update_2(t_token *token, char *var, size_t length)
{
	size_t	i;
	char	**new_env;

	new_env = malloc(sizeof(char *) * (length + 2));
	if (new_env == NULL)
		return (ft_putendl_fd("Malloc failed in the export builtin!", 2));
	i = 0;
	while (i < length)
	{
		new_env[i] = token->envp[i];
		i++;
	}
	new_env[i++] = var;
	new_env[i] = NULL;
	free(token->envp);
	token->envp = new_env;
}

/*
 * Compares the two given strings until either a character that is not the
 * same is encountered. If one of them reaches the end and the other does not,
 * the other has to end with the given character. If only one of the two
 * strings is null, false is returned.
 */
static bool	string_compare_until(char *self, char *other, char end)
{
	size_t	i;

	if (self == NULL && other == NULL)
		return (true);
	if ((self != NULL && other == NULL)
		|| (self == NULL && other != NULL))
		return (false);
	i = 0;
	while (self[i] != '\0' && other[i] != '\0'
		&& other[i] != end && self[i] != end)
	{
		if (self[i] != other[i])
			return (false);
		i++;
	}
	if ((other[i] == '\0' && self[i] == end)
		|| (self[i] == '\0' && other[i] == end)
		|| self[i] == other[i])
		return (true);
	return (false);
}

/*
 * Replaces a variable that already exists in the environment. If that is not
 * the case, the variable will be appended.
 */
static void	builtin_export_update(t_token *token, char *var)
{
	size_t	i;

	i = 0;
	while (token->envp != NULL && token->envp[i] != NULL)
	{
		if (string_compare_until(token->envp[i], var, '='))
		{
			free(token->envp[i]);
			token->envp[i] = var;
			return ;
		}
		i++;
	}
	builtin_export_update_2(token, var, i);
}

/*
 * Checks each argument if it is a valid identifier. If that is the case, the
 * argument is treated as a variable and appended or inserted to the
 * environment. If an argument is not a valid identifier, 1 is returned.
 */
static int	builtin_export_checker(t_token *t)
{
	int		status;
	size_t	i;

	status = 0;
	i = 1;
	while (t->c_args[i] != NULL)
	{
		if ((ft_strchr(t->c_args[i], '=') != NULL
				&& utils_is_identifier_length(t->c_args[i],
					ft_strchr(t->c_args[i], '=') - t->c_args[i]))
			|| utils_is_identifier(t->c_args[i]))
			builtin_export_update(t, t->c_args[i]);
		else
		{
			free(t->c_args[i]);
			ft_putstr_fd("Not a valid identifier: \'", 2);
			ft_putstr_fd(t->c_args[i], 2);
			ft_putendl_fd("\'", 2);
			status = 1;
		}
		i++;
	}
	t->c_args = NULL;
	return (status);
}

int	builtin_export(t_token *t)
{
	size_t	i;
	size_t	j;
	int		mode;

	i = 0;
	while (t->c_args[1] == NULL && t->envp != NULL && t->envp[i] != NULL)
	{
		j = 0;
		mode = write(1, "declare -x ", 12);
		while (t->envp[i][j] != '\0')
		{
			write(1, &t->envp[i][j], 1);
			if (t->envp[i][j] == '=' && mode != 1)
				mode = write(1, "\"", 1);
			j++;
		}
		if (mode == 1)
			write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
	return (builtin_export_checker(t));
}
