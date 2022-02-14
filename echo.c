#include <stdio.h>

#include "echo.h"

int	builtin_echo(char **argv)
{
	size_t	i;

	i = 1;
	while (argv[i] != NULL)
	{
		printf("%s", argv[i]);
		if (argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
	printf("\n");
	return (0);
}
