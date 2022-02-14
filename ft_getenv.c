#include <stddef.h>

#include "libft.h"

#include "utils.h"

char	*ft_getenv_entry(const char *var, char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (string_starts_with_ec(env[i], var, '=')
			|| string_starts_with_ec(env[i], var, '\0'))
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*ft_getenv(const char *var, char **env)
{
	char	*entry;

	entry = ft_getenv_entry(var, env);
	if (entry != NULL)
	{
		entry = ft_strchr(entry, '=');
		if (entry != NULL)
			return (entry + 1);
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
