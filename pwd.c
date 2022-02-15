#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "pwd.h"

int	builtin_pwd(char **argv)
{
	char	*pwd;

	(void) argv;
	pwd = NULL;
	pwd = getcwd(pwd, 0);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
