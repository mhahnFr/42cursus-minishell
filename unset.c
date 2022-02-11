#include <stdlib.h>

#include "libft.h"

#include "unset.h"
#include "utils.h"

#include <stdio.h>
static void	builtin_unset_remove(char *var, char ***env)
{
	char	**new_env;
	char	*del;
	size_t	i;
	size_t	j;

	del = NULL;
	i = 0;
	while ((*env)[i] != NULL)
	{
		if (string_starts_with_ec((*env)[i], var, '='))
			del = (*env)[i];
		i++;
	}
	printf("To delete: %s\n", del);
	if (del != NULL)
	{
		new_env = malloc(get_env_size((const char **) *env) * sizeof(char *));
		i = 0;
		j = 0;
		while ((*env)[i] != NULL)
		{
			if ((*env)[i] != del)
			{
				new_env[j] = (*env)[i];
				j++;
			}
			i++;
		}
		new_env[j] = NULL;
		free(*env);
		free(del);
		*env = new_env;
	}
}

int	builtin_unset(char **argv, char ***env)
{
	int		status;
	size_t	i;

	status = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (utils_is_identifier(argv[i]))
			builtin_unset_remove(argv[i], env);
		else
		{
			status = 1;
			ft_putstr_fd("Invalid identifier: \'", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putendl_fd("\'", 2);
		}
		i++;
	}
	return (status);
}
