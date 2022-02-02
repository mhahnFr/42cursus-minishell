#include "libft.h"

#include "token.h"
#include "env.h"

int	builtin_check(t_token *token)
{
	if (ft_strncmp(token->c_args[0], "env", ft_strlen(token->c_args[0])) == 0)
		return (1);
	return (0);
}

int	builtin_exec(t_token *token)
{
	if (ft_strncmp(token->c_args[0], "env", ft_strlen(token->c_args[0])) == 0)
		return (builtin_env(token->c_args, token->envp));
	return (-1);
}
