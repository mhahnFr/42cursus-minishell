#include "libft.h"

#include "cd.h"
#include "echo.h"
#include "env.h"
#include "exit.h"
#include "export.h"
#include "pwd.h"
#include "token.h"
#include "unset.h"
#include "utils.h"

int	builtin_check(t_token *token)
{
	return (ft_strncmp(token->c_args[0], "env", ft_strlen(token->c_args[0]))
		== 0
		|| ft_strncmp(token->c_args[0], "pwd", ft_strlen(token->c_args[0]))
		== 0
		|| ft_strncmp(token->c_args[0], "cd", ft_strlen(token->c_args[0]))
		== 0
		|| ft_strncmp(token->c_args[0], "echo", ft_strlen(token->c_args[0]))
		== 0
		|| ft_strncmp(token->c_args[0], "export", ft_strlen(token->c_args[0]))
		== 0
		|| ft_strncmp(token->c_args[0], "unset", ft_strlen(token->c_args[0]))
		== 0
		|| ft_strncmp(token->c_args[0], "exit", ft_strlen(token->c_args[0]))
		== 0);
}

int	builtin_exec(t_token *t)
{
	int	exit_status;

	exit_status = -1;
	if (ft_strncmp(t->c_args[0], "env", ft_strlen(t->c_args[0])) == 0)
		exit_status = builtin_env(t->c_args, t->envp);
	else if (ft_strncmp(t->c_args[0], "pwd", ft_strlen(t->c_args[0])) == 0)
		exit_status = builtin_pwd(t->c_args);
	else if (ft_strncmp(t->c_args[0], "cd", ft_strlen(t->c_args[0])) == 0)
		exit_status = builtin_cd(t->c_args);
	else if (ft_strncmp(t->c_args[0], "echo", ft_strlen(t->c_args[0])) == 0)
		exit_status = builtin_echo(t->c_args);
	else if (ft_strncmp(t->c_args[0], "export", ft_strlen(t->c_args[0])) == 0)
		exit_status = builtin_export(t->c_args, t->envp);
	else if (ft_strncmp(t->c_args[0], "unset", ft_strlen(t->c_args[0])) == 0)
		exit_status = builtin_unset(t->c_args, t->envp);
	else if (ft_strncmp(t->c_args[0], "exit", ft_strlen(t->c_args[0])) == 0)
		exit_status = builtin_exit(t->c_args);
	utils_free_double_pointer(&t->c_args);
	return (exit_status);
}
