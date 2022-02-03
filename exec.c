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

bool	exec_run(t_token *token, char *env)
{
	char	*cmd_w_path;
	int		i;
	pid_t	child;
	int		status;

	i = 0;
	while (env[i] != '\0' && env[i] != ':')
		i++;
	if (i == 0)
	{
		ft_putstr_fd(NAME ": command not found: ", 2);
		ft_putendl_fd(token->c_args[0], 2);
		utils_free_double_pointer(&token->c_args);
		return (-1);
	}
	cmd_w_path = str_copy(token->c_args[0], i + 1);
	cmd_w_path[i] = '/';
	while (i > 0)
	{
		i--;
		cmd_w_path[i] = env[i];
	}
	while (env[i] != '\0' && env[i] != ':')
		i++;
	if (0 != access(cmd_w_path, X_OK))
	{
		free(cmd_w_path);
		return (exec_run(token, &env[i + 1]));
	}
	child = fork();
	if (0 == child)
		exit(execve(cmd_w_path, token->c_args, token->envp));
	if (0 > child)
		return (false);
	utils_free_double_pointer(&token->c_args);
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		token->exitstat = WEXITSTATUS(status);
	else
		token->exitstat = -1;
	return (tokenizer_func(token));
}
