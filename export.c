#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"

#include "env.h"
#include "export.h"
#include "token.h"
#include "utils.h"

void	builtin_export_update_2(t_token *token, char **vars, int i)
{
	char	**newenv;

	newenv = malloc(sizeof(char **) * (i + 2));
	newenv[i + 1] = NULL;
	newenv[i] = vars[0];
	while (i != 0)
	{
		i--;
		newenv[i] = token->envp[i];
	}
	free(token->envp);
	token->envp = newenv;
}

void	builtin_export_update(t_token *token, char **vars)
{
	int		i;
	int		j;

	if (vars == NULL || vars[0] == NULL)
		return ;
	i = 0;
	while (token->envp != NULL && token->envp[i] != NULL)
	{
		j = 0;
		while (token->envp[i][j] == vars[0][j] && vars[0][j] != '\0'
			&& vars[0][j] != '=')
			j++;
		if ((token->envp[i][j] == '=' || token->envp[i][j] == '\0') && j != 0)
		{
			free(token->envp[i]);
			token->envp[i] = vars[0];
			return (builtin_export_update(token, &vars[1]));
		}
		i++;
	}
	builtin_export_update_2(token, vars, i);
}

int	builtin_export(t_token *t)
{
	size_t	i;
	size_t	j;
	int		mode;
	int		status;

	status = 0;
	i = 0;
	while (t->c_args[1] == NULL && t->envp != NULL && t->envp[i] != NULL)
	{
		j = 0;
		mode = write(1, "declare -x ", 12);
		while (t->envp[i][j] != '\0')
		{
			write(1, &t->envp[i][j], 1);
			if (t->envp[i][j] == '=' && mode != 1)
				mode = write(1, "\"", 1);
			j++;
		}
		if (mode == 1)
			write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
	for (size_t i = 1; t->c_args[i] != NULL; i++) {
		if (utils_is_identifier(t->c_args[i]))
			builtin_export_update(t, &t->c_args[i]);
		else
		{
			ft_putstr_fd("Not a valid identifier: \"", 2);
			ft_putstr_fd(t->c_args[i], 2);
			ft_putendl_fd("\"", 2);
			status = 1;
		}
	}
	//free(t->c_args[0]);
	//t->c_args = NULL;
	return (status);
}
