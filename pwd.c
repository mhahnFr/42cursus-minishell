#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"

#include "pwd.h"

int	builtin_pwd(char **argv)
{
	char	*pwd;

	if (argv[1] != NULL)
	{
		ft_putendl_fd("Too many arguments!", 2);
		return (1);
	}
	pwd = NULL;
	pwd = getcwd(pwd, 1);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
