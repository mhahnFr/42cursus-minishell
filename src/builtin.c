/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:59:38 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 22:40:52 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "cd.h"
#include "tokenizer.h"
#include "echo.h"
#include "env.h"
#include "exit.h"
#include "export.h"
#include "pwd.h"
#include "token.h"
#include "unset.h"
#include "utils.h"

bool	builtin_check(t_token *token)
{
	const char	*arg;

	arg = token->c_args[0];
	return (string_equals(arg, "env")
		|| string_equals(arg, "export")
		|| string_equals(arg, "unset")
		|| string_equals(arg, "pwd")
		|| string_equals(arg, "echo")
		|| string_equals(arg, "cd")
		|| string_equals(arg, "exit"));
}

void	builtin_close_fds(t_token *t, int *i, int *j)
{
	(*j) = -1;
	(*i) = -1;
	if (t->fdout != -1)
	{
		*j = dup(1);
		dup2(t->fdout, 1);
		close(t->fdout);
	}
	if (t->fdin != -1)
	{
		(*i) = dup(0);
		dup2(t->fdin, 0);
		close(t->fdin);
	}
}

void	builtin_replace_fds(int i, int j)
{
	if (i != -1)
	{
		dup2(i, 0);
		close(i);
	}
	if (j != -1)
	{
		dup2(j, 1);
		close(j);
	}
}

int	builtin_exec(t_token *t)
{
	int			i;
	int			j;
	const char	*arg;

	builtin_close_fds(t, &i, &j);
	arg = t->c_args[0];
	if (string_equals(arg, "env"))
		t->exitstat = builtin_env(t->c_args, t->envp);
	else if (string_equals(arg, "pwd"))
		t->exitstat = builtin_pwd(t->c_args);
	else if (string_equals(arg, "export"))
		t->exitstat = builtin_export(t);
	else if (string_equals(arg, "exit"))
		t->exitstat = builtin_exit(t->c_args, t);
	else if (string_equals(arg, "echo"))
		t->exitstat = builtin_echo(t->c_args);
	else if (string_equals(arg, "unset"))
		t->exitstat = builtin_unset(t->c_args, &t->envp);
	else if (string_equals(arg, "cd"))
		t->exitstat = builtin_cd(t->c_args, t->envp);
	utils_free_token(t, 0);
	builtin_replace_fds(i, j);
	return (tokenizer_func(t));
}
