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
	const char	*arg;

	arg = token->c_args[0];
	return (string_equals(arg, "env")
		|| string_equals(arg, "export")
		|| string_equals(arg, "pwd")
		|| string_equals(arg, "exit"));
}

int	builtin_exec(t_token *t)
{
	int			exit_status;
	const char	*arg;

	exit_status = -1;
	arg = t->c_args[0];
	if (string_equals(arg, "env"))
		exit_status = builtin_env(t->c_args, t->envp);
	else if (string_equals(arg, "pwd"))
		exit_status = builtin_pwd(t->c_args);
	else if (string_equals(arg, "export"))
		exit_status = builtin_export(t->c_args, &t->envp);
	else if (string_equals(arg, "exit"))
		exit_status = builtin_exit(t->c_args, t);
	utils_free_token(t, 0);
	return (exit_status);
}
