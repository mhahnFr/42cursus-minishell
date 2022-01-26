#include <sys/wait.h>
#include <unistd.h>

#include "token.h"
#include "tokenizer.h"
#include "skip.h"

int	pipe_check(t_token *token)
{
	int		i;
	int		prthcnt;
	char	qtm;

	i = 0;
	prthcnt = 0;
	qtm = ' ';
	while ((token->strlen != -1 && (token->str)[i] != '\0')
		|| i < token->strlen)
	{
		if ((token->str)[i] == '|')
			return (i);
		while ((token->str)[i] == '(' || prthcnt != 0)
		{
			if ((token->str)[i] == '(')
				prthcnt++;
			else if ((token->str)[i] == ')')
				prthcnt--;
			i = i + skip_qtm_and_move(&(token->str)[i]);
		}
		i = i + skip_qtm_and_move(&(token->str)[i]);
	}
	return (0);
}

int	pipe_func(t_token *token)
{
	int		pipe_fds[2];
	pid_t	child1;
	pid_t	child2;

	if (pipe(pipe_fds) == -1)
		return (-1); // TODO FREE TOKEN
	child1 = fork();
	if (child1 < 0)
		return (-1); // TODO FREE TOKEN
	if (0 == child1)
	{
		token->strlen = pipe_check(token);
		token->outfd = pipe_fds[0];
		tokenizer_func(token);
	}
	child2 = fork();
	if (child2 < 0)
		return (-1); // TODO FREE TOKEN
	if (0 == child2)
	{
		token->str = &(token->str)[pipe_check(token)];
		token->strlen = token->strlen - pipe_check(token);
		token->outfd = pipe_fds[0];
	}
	waitpid(child1, NULL, 0); // TODO if NULL not needed remove include unistd
	return (waitpid(child2, NULL, 0));
}
