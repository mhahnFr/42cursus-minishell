#include <stdlib.h>

#include "exit.h"
#include "utils.h"

int	builtin_exit(char **argv, t_token *token)
{
	if (argv != NULL && argv[1] != NULL)
	{
		
	}
	exit(utils_free_token(token, 2));
	return (0);
}
