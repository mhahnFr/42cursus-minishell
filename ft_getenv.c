#include <stddef.h>

#include "utils.h"

char	*ft_getenv(const char *var, char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (string_starts_with_ec(env[i], var, '='))
			return (env[i]);
		i++;
	}
	return ("");
}

bool	ft_hasenvvar(const char *var, char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (string_starts_with_ec(env[i], var, '='))
			return (true);
		i++;
	}
	return (false);
}
