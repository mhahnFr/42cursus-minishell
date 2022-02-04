#include <stddef.h>

#include "env.h"
#include "export.h"

int	builtin_export(char **argv, char ***env)
{
	if (argv[1] == NULL)
		return (builtin_env(argv, *env));
	return (0);
}
