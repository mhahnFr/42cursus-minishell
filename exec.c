#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "libft.h"
#include "minishell.h"
#include "str.h"
#include "token.h"
#include "tokenizer.h"
#include "utils.h"

char	*exec_get_path(t_token *token, char *e)
{
	char	*cmd_w_path;
	int		i;

	if (token->c_args == NULL || token->c_args[0] == NULL)
		return (0);
	if (e[0] == ':')
		e++;
	i = 0;
	while (e[i] != '\0' && e[i] != ':')
		i++;
	cmd_w_path = malloc(sizeof(char *) * (i + ft_strlen(token->c_args[0]) + 2));
	ft_strlcpy(cmd_w_path, e, i + 1);
	cmd_w_path[i] = '/';
	ft_strlcpy(&cmd_w_path[i + 1], token->c_args[0],
		ft_strlen(token->c_args[0]) + 1);
	if (0 == access(cmd_w_path, X_OK))
		return (cmd_w_path);
	free(cmd_w_path);
	if (e[i] == '\0')
		return (NULL);
	return (exec_get_path(token, &e[i]));
}

pid_t	exec_fork(t_token *token, char	*cmdstr, pid_t child)
{
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
	if (token->fdout != -1)
		close(token->fdout);
	if (token->fdin != -1)
		close(token->fdin);
	free(cmdstr);
	if (0 < child)
		return (child);
	utils_free_token(token, 2);
	exit(-1);
}

bool	exec_run(t_token *token, char *env)
{
	char	*cmdstr;
	int		stat;

	stat = 0;
	while (token->c_args[0][stat] == '.')
		stat++;
	if (token->c_args[0][stat] == '/' && 0 == access(token->c_args[0], X_OK))
		cmdstr = ft_strdup(token->c_args[0]);
	else
		cmdstr = exec_get_path(token, env);
	if (cmdstr == NULL)
	{
		ft_putstr_fd(NAME ": command not found: ", 2);
		ft_putendl_fd(token->c_args[0], 2);
		token->exitstat = 127;
		return (utils_free_token(token, 1));
	}
	waitpid(exec_fork(token, cmdstr, fork()), &stat, 0);
	utils_free_token(token, 0);
	if (WIFEXITED(stat))
		token->exitstat = WEXITSTATUS(stat);
	else
		token->exitstat = -1;
	return (tokenizer_func(token));
}
