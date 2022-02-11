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

char	*get_envar(char **env, char *str, int *slen, char mode)
{
	int	j;

	while (env != NULL && *env != NULL)
	{
		j = 0;
		while ((*env)[j] == str[j + 1] && j < *slen - 1)
			j++;
		if ((*env)[j] == '=' && j == *slen - 1)
		{
			if (mode != '\'' && mode != '"')
				while ((*env)[j + 1] == ' ' && (*env)[j + 2] == ' ')
					j++;
			*slen = 0;
			while ((*env)[j + 1 + *slen] != '\0')
				(*slen)++;
			if (mode != '\'' && mode != '"')
				while ((*env)[j + *slen] == ' ' && (*env)[j + *slen - 1] == ' ')
					(*slen)--;
			return (&env[0][j + 1]);
		}
		env++;
	}
	*slen = 0;
	return (NULL);
}
