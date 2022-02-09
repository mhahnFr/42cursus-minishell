#include <stdlib.h>

#include "exit.h"
#include "utils.h"

int	builtin_exit(char **argv)
{
	(void) argv;
	return (0);
}

void	builtin_prompt_exit(t_token *token)
{
	utils_free_double_pointer(&token->envp);
	exit(token->exitstat);
}
