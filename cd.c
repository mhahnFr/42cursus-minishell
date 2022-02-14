#include <stdio.h>
#include <unistd.h>

#include "libft.h"

#include "cd.h"
#include "utils.h"

int	builtin_cd(char **argv, char **env)
{
	int		ret;
	char	*env_home;

	env_home = NULL;
	ret = 0;
	if (argv[1] == NULL)
	{
		if (ft_hasenvvar("HOME", env))
			env_home = ft_getenv("HOME", env);
		else
		{
			ft_putendl_fd("cd: home not set!", 2);
			ret = 1;
		}
	}
	else if (argv[1][0] != '\0')
		env_home = argv[1];
	if (env_home != NULL)
	{
		ret = chdir(env_home);
		if (ret != 0)
			perror(argv[1]);
	}
	return (ret);
}
