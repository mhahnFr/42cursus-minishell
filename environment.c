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
		return (NULL); // TODO Error handling
	index = 0;
	while (environ[index] != NULL)
	{
		ret[index] = ft_strdup(environ[index]);
		index++;
	}
	ret[index] = NULL;
	return (ret);
}
