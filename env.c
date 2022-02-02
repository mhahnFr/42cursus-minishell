#include <stdio.h>

#include "libft.h"

#include "env.h"

int	builtin_env(char **argv, char **env)
{
	size_t		index;

	if (argv[1] != NULL)
	{
		ft_putendl_fd("Too many arguments!\n", 2);
		return (1);
	}
	index = 0;
	while (env[index] != NULL)
	{
		printf("%s\n", env[index]);
		index++;
	}
	return (0);
}
