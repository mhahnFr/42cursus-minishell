#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "token.h"
#include "tokenizer.h"

int	pipe_skip_qtm_and_move(char *str)
{
	int		i;

	i = 1;
	if (str[0] == '"' || str[0] == '\'')
		while (str[i] != str[0])
			i++;
	return (i);
}

int	pipe_check(t_token *token)
{
	int		i;
	int		prthcnt;
	char	qtm;

	i = 0;
	prthcnt = 0;
	qtm = ' ';
	while (i < token->strlen)
	{
		if ((token->str)[i] == '|')
			return (i);
		while ((token->str)[i] == '(' || prthcnt != 0)
		{
			if ((token->str)[i] == '(')
				prthcnt++;
			else if ((token->str)[i] == ')')
				prthcnt--;
			i = i + pipe_skip_qtm_and_move(&(token->str)[i]);
		}
		i = i + pipe_skip_qtm_and_move(&(token->str)[i]);
	}
	return (0);
}

int	pipe_func(t_token *token)
{
	int		pipe_fds[2];
	int		len;
	pid_t	child1;
	pid_t	child2;
	int		status;

	len = pipe_check(token);
	if (pipe(pipe_fds) == -1)
		return (-1); // TODO FREE TOKEN
	child1 = fork();
	if (child1 < 0)
		return (-1); // TODO FREE TOKEN
	if (0 == child1)
	//if (1)
	{
		token->strlen = len - 1;
		dup2(pipe_fds[1], 1);
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		exit(tokenizer_func(token));
	}
	child2 = fork();
	if (child2 < 0)
		return (-1); // TODO FREE TOKEN
	if (0 == child2)
	//if (1)
	{
		token->strlen = token->strlen - len - 1;
		token->str = &token->str[len + 1];
		dup2(pipe_fds[0], 0);
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		exit(tokenizer_func(token));
	}
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	waitpid(child1, NULL, 0); // TODO if NULL not needed remove include unistd
	waitpid(child2, &status, 0);
	return (status);
}
