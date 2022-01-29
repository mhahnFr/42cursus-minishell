#include <stddef.h>
#include <unistd.h>

#include "tokenizer.h"
#include "pipe.h"
#include "check.h"
#include "pipe.h"
#include "parse.h"

t_token	*tokenizer_apply_or_and(t_token *token)
{
	token = NULL;
	return (NULL);
}

int	tokenizer_apply_parenthesis(t_token *token)
{
	token = NULL;
	return (0);
}

t_token	*tokenizer_apply_result(t_token *token, int res)
{
	res = 0;
	(void)token;
	return (NULL);
}

int	tokenizer_func(t_token *token)
{
	int	res;

	// if (check_or_and(token))
	// 	return (tokenizer_func(tokenizer_apply_or_and(token)));
	if (pipe_check(token))
		return (pipe_func(token));
	// if (check_parenthesis(token))
	// 	return (tokenizer_apply_parenthesis(token));
	parse_func(token);
	res = 0;
	return (1);
	//return (tokenizer_func(tokenizer_apply_result(token, res)));
}
