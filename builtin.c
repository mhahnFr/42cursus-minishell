#include "token.h"

int	builtin_check(t_token *token)
{
	(void) token;
	return (0);
}

int	builtin_exec(t_token *token)
{
	return (token->strlen);
}
