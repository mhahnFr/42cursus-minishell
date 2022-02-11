#include "libft.h"

#include "unset.h"
#include "utils.h"

static void	builtin_unset_remove(char *var, char ***env)
{
	(void) var;
	(void) env;
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
			status = 1;
		i++;
	}
	return (status);
}
