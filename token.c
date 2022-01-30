#include <stdlib.h>

#include "token.h"

void	token_next_arg(t_token *token)
{
	int		i;
	int		j;

	i = 0;
	while (token->str[i] == ' ')
		i++;
	while (token->str[i] != ' ' && token->str[i] != '\0')
	{
		if (token->str[i] == '"' || token->str[i] == '\'')
		{
			j = i;
			i++;
			while (token->str[i] != token->str[j])
				i++;
		}
		i++;
	}
	token->str = &token->str[i];
	token->strlen =  token->strlen - i;
}

void	move_one_char(t_token *token)
{
	token->str = &token->str[1];
	token->strlen =  token->strlen - 1;
}