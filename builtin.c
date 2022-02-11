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
		|| string_equals(arg, "unset")
		|| string_equals(arg, "pwd")
		|| string_equals(arg, "exit"));
}

int	builtin_exec(t_token *t)
{
	const char	*arg;

	arg = t->c_args[0];
	if (string_equals(arg, "env"))
		t->exitstat = builtin_env(t->c_args, t->envp);
	else if (string_equals(arg, "pwd"))
		t->exitstat = builtin_pwd(t->c_args);
	else if (string_equals(arg, "export"))
		t->exitstat = builtin_export(t->c_args, &t->envp);
	else if (string_equals(arg, "exit"))
		t->exitstat = builtin_exit(t->c_args, t);
	else if (string_equals(arg, "unset"))
		t->exitstat = builtin_unset(t->c_args, &t->envp);
	utils_free_token(t, 0);
	return (t->exitstat);
}
