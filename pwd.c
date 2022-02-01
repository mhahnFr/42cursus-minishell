#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "pwd.h"

int	builtin_pwd(char **argv)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
