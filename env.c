#include <stdio.h>

#include "libft.h"

#include "env.h"

int	builtin_env(char **argv)
{
	size_t		index;
	extern char	**environ;

	if (*argv != NULL)
	{
		ft_putendl_fd("Too many arguments!\n", 2);
		return (1);
	}
	index = 0;
	while (environ[index] != NULL)
	{
		printf("%s\n", environ[index]);
		index++;
	}
	return (0);
}
