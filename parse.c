#include <stdlib.h>

#include "builtin.h"
#include "exec.h"
#include "file.h"
#include "libft.h"
#include "str.h"
#include "token.h"
#include "utils.h"

void	parse_c_arg(t_token *token)
{
	int		i;
	char	**tmp;

	i = 0;
	while (token->c_args != NULL && token->c_args[i] != NULL)
		i++;
	tmp = token->c_args;
	token->c_args = malloc(sizeof(char *) * (i + 2));
	if (token->c_args == NULL)
		exit (-1);
	i = 0;
	while (tmp != NULL && tmp[i] != NULL)
	{
		token->c_args[i] = tmp[i];
		i++;
	}
	if (tmp != NULL)
		free(tmp);
	token->c_args[i] = str_copy(token);
	token->c_args[i + 1] = NULL;
}

int	parse_func(t_token *token)
{
	while (token->strlen > 0)
	{
		if ((token->str)[0] == '>' && (token->str)[1] == '>')
			file_append(token);
		else if (token->str[0] == '>')
			file_write(token);
		else if ((token->str)[0] == '<' && (token->str)[1] == '<')
			file_heredoc(token);
		else if (token->str[0] == '<')
			file_open(token);
		else if (token->str[0] != ' ')
			parse_c_arg(token);
		else
			token_move_one_char(token);
	}
	if (token->c_args != NULL && builtin_check(token))
		return (builtin_exec(token));
	if (token->c_args != NULL)
		return (exec_run(token, ft_getenv("PATH", token->envp)));
	return (1);
}
