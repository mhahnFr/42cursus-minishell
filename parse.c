#include <stdlib.h>

#include "token.h"
#include "str.h"
#include "libft.h"
#include "utils.h"
#include "exec.h"
#include "file.h"


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
	token->c_args[i] = str_copy(token->str, 0);
	token->strlen = token->strlen + 1 - ft_strlen(token->c_args[i]);
	token->str = &token->str[ft_strlen(token->c_args[i])];
	token->c_args[i + 1] = NULL;
}

void	parse_func(t_token *token)
{
	while(token->strlen > 0)
	{
		if ((token->str)[0] == '>' && (token->str)[1] == '>')
			file_append(token);
		else if (token->str[0] == '>')
			file_write(token);
		// else if ((token->str)[0] == '<' && (token->str)[1] == '<')
		// 	file_append(token);
		else if (token->str[0] == '<')
			file_open(token);
		else if (token->str[0] != ' ')
			parse_c_arg(token);
		else
			token->str = &token->str[1];
		token->strlen = token->strlen - 1;
	}
	if (token->c_args != NULL)
		exec_run(token, getenv("PATH"));
}