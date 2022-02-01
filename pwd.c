#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"

#include "pwd.h"

int	builtin_pwd(char **argv)
{
	char	*pwd;

	if (*argv != NULL)
	{
		ft_putendl("Too many arguments!", 2);
		return (1);
	}
	pwd = NULL;
	pwd = getcwd(pwd);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
