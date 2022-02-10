#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "token.h"
#include "tokenizer.h"
#include "utils.h"

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

	i = 0;
	prthcnt = 0;
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

pid_t	pipe_childs(int childno, t_token *token, int len, int pipe_fds[2])
{
	pid_t	child;

	child = fork();
	if (child < 0)
		return (-1);
	if (childno == 0 && 0 == child)
	{
		token->strlen = len - 1;
		token->str[token->strlen] = '\0';
		dup2(pipe_fds[1], 1);
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		exit(tokenizer_func(token));
	}
	else if (childno == 1 && 0 == child)
	{
		token->strlen = token->strlen - len - 1;
		token->str = &token->str[len + 1];
		token->str[token->strlen] = '\0';
		dup2(pipe_fds[0], 0);
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		exit(tokenizer_func(token));
	}
	return (child);
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
		return (-1);
	child1 = pipe_childs(0, token, len, pipe_fds);
	if (child1 == -1)
		return (-1);
	child2 = pipe_childs(1, token, len, pipe_fds);
	if (child2 == -1)
		return (-1);
	waitpid(child1, NULL, 0);
	waitpid(child2, &status, 0);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	if (WIFEXITED(status))
		token->exitstat = WEXITSTATUS(status);
	else
		token->exitstat = -1;
	return (utils_free_token(token, 1));
}
