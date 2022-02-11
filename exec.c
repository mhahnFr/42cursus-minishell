#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stdlib.h>

#include "minishell.h"
#include "token.h"
#include "str.h"
#include "utils.h"
#include "libft.h"
#include "tokenizer.h"

char	*exec_get_path(t_token *token, char *env)
{
	char	*cmd_w_path;
	int		i;

	if (env[0] == ':')
		env++;
	i = 0;
	while (env[i] != '\0' && env[i] != ':')
		i++;
	cmd_w_path = str_copy(token, i);
	while (i > 0 && env[0] != '\0')
	{
		i--;
		cmd_w_path[i] = env[i];
	}
	while (env[i] != '\0' && env[i] != ':')
		i++;
	if (0 == access(cmd_w_path, X_OK))
		return (cmd_w_path);
	free(cmd_w_path);
	if (i == 1 && env[1] == '\0' && env[0] == '.')
		return (NULL);
	if (env[i] == '\0')
		return (exec_get_path(token, "."));
	return (exec_get_path(token, &env[i]));
}

bool	exec_run(t_token *token, char *env)
{
	char	*cmdstr;
	pid_t	child;
	int		status;

	cmdstr = exec_get_path(token, env);
	if (cmdstr == NULL)
	{
		ft_putstr_fd(NAME ": command not found: ", 2);
		ft_putendl_fd(token->c_args[0], 2);
		token->exitstat = 127;
		return (utils_free_token(token, 1));
	}
	child = fork();
	if (0 == child)
	{
		if (token->fdout != -1)
		{
			dup2(token->fdout, 1);
			close(token->fdout);
		}
		if (token->fdin != -1)
		{
			dup2(token->fdin, 0);
			close(token->fdin);
		}
		exit(execve(cmdstr, token->c_args, token->envp));
	}
	if (0 > child)
		return (false); // TODO errormanagment
	utils_free_token(token, 0);
	free(cmdstr);
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		token->exitstat = WEXITSTATUS(status);
	else
		token->exitstat = -1;
	return (tokenizer_func(token));
}
