#include <stdio.h>

#include "echo.h"

int	builtin_echo(char **argv)
{
	size_t	i;

	i = 1;
	if (argv != NULL && argv[1] != NULL && argv[1][0] == '-'
		&& argv[1][0] == 'n' && argv[1][0] == '\0')
		i++;
	while (argv[i] != NULL)
	{
		printf("%s", argv[i]);
		if (argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!(argv != NULL && argv[1] != NULL && argv[1][0] == '-'
		&& argv[1][0] == 'n' && argv[1][0] == '\0'))
		printf("\n");
	return (0);
}
