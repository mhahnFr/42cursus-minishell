#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

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

int	tokenizer_check_parenthesis(t_token *token)
{
	int		i;

	i = 0;
	while (token->str[i] == ' ')
		i++;
	if (token->str[i] == '(')
	{
		token->str = &token->str[i + 1];
		token->strlen = token->strlen - (i + 1);
		return (1);
	}
	return (0);
}

int	tokenizer_apply_parenthesis(t_token *token)
{
	pid_t	child;
	int		status;

	child = fork();
	if (child < 0)
		return (-1); // TODO FREE TOKEN
	if (0 == child)
	{
		while (token->str[token->strlen] != ')')
			token->strlen--;
		token->strlen--;
		exit(tokenizer_func(token));
	}
	token->str = &token->str[token->strlen];
	token->strlen = 0;
	waitpid(child, &status, 0);
	return (status);
}

int	tokenizer_func(t_token *token)
{
	if (token->str[0] == '\0')
		return (1);
	// if (check_or_and(token))
	// 	return (tokenizer_func(tokenizer_apply_or_and(token)));
	else if (pipe_check(token))
		return (pipe_func(token));
	else if (tokenizer_check_parenthesis(token))
		return (tokenizer_apply_parenthesis(token));
	else
		return (parse_func(token));
}
