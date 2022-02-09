#include <stdlib.h>

#include "exit.h"
#include "utils.h"

int	builtin_exit(char **argv, t_token *token)
{
	if (argv != NULL && argv[1] != NULL)
	{
		
	}
	if (token->c_args != NULL)
		utils_free_double_pointer(&token->c_args);
	utils_free_double_pointer(&token->envp);
	exit(token->exitstat);
	return (0);
}
