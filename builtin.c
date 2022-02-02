#include "libft.h"

#include "env.h"
#include "pwd.h"
#include "token.h"
#include "utils.h"

int	builtin_check(t_token *token)
{
	if (ft_strncmp(token->c_args[0], "env", ft_strlen(token->c_args[0])) == 0
		|| ft_strncmp(token->c_args[0], "pwd", ft_strlen(token->c_args[0])) == 0)
		return (1);
	return (0);
}

int	builtin_exec(t_token *token)
{
	int	exit_status;

	exit_status = -1;
	if (ft_strncmp(token->c_args[0], "env", ft_strlen(token->c_args[0])) == 0)
		exit_status = builtin_env(token->c_args, token->envp);
	else if (ft_strncmp(token->c_args[0], "pwd", ft_strlen(token->c_args[0])) == 0)
		exit_status = builtin_pwd(token->c_args);
	utils_free_double_pointer(&token->c_args);
	return (exit_status);
}
