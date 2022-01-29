#include <unistd.h>

#include "token.h"
#include "str.h"
#include "libft.h"

// void	parse_infile(char *file)
// {

// }

void	parse_func(t_token *token)
{
	int	i;

	i = 0;
	while(i != token->strlen)
	{
		if ((token->str)[i] == '<' && (token->str)[i + 1] == '<')
		{
			while ((token->str)[i + 2] == ' ')
				i++;
			write(1, str_copy(&(token->str)[i + 2]), ft_strlen(str_copy(&(token->str)[i + 2])));
		}
		i++;

		// if ((token->str)[i] == '<' && (token->str)[i + 1] == '<')
		// 	i = parse_here_document(&(token->str)[i + 2]);
		// else if ((token->str)[i] == '<')
		// 	i = parse_infile(&(token->str)[i + 1]);
		// else if ((token->str)[i] == '>' && (token->str)[i + 1] == '>')
		// 	i = parse_append_outfile(&(token->str)[i + 2]);
		// else if ((token->str)[i] == '>')
		// 	i = parse_outfile(&(token->str)[i + 2]);
	}
}