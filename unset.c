#include "libft.h"

#include "unset.h"

int	builtin_unset(char **argv, char **env)
{
	if (argv[1] == NULL)
	{
		ft_putendl_fd("Not enough arguments!\n", 2);
		return (1);
	}
	(void) env;
	return (0);
}
