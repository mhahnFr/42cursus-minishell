#include <stdlib.h>

#include "token.h"
#include "env.h"
#include "str.h"
#include "libft.h"

int	str_replace_len(t_token *token, char *s, char **dst, char c)
{
	int		i;
	char	*str;
	int		j;

	if (s[0] == '$' && s[1] == '?')
		return (str_exitstat(token, dst));
	i = 1;
	while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A'
			&& s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
		i++;
	if (i == 1 && dst != NULL)
		**dst = '$';
	if (i == 1)
		return (1);
	str = get_envar(token->envp, s, &i, c);
	j = 0;
	while (dst != NULL && j != i)
	{
		(*dst)[j] = str[j];
		j++;
	}
	return (i);
}

int	str_get_malloc_len(t_token *token, char *s, int strlen, char c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (((s[i] != ' ' && s[i] != '<' && s[i] != '>')
			|| c == '"' || c == '\'') && i < strlen)
	{
		if (c != '\'' && c != '"')
			c = s[i];
		else if (c == s[i])
			c = s[i + 1];
		i++;
		if ((s[i - 1] != '"' && s[i - 1] != '\'' && s[i - 1] != '$')
			|| (s[i - 1] == '$' && c == '\'') || ((s[i - 1] == '"'
					|| s[i - 1] == '\'') && (c == '\'' || c == '"')))
			len++;
		else if (s[i - 1] == '$' && c != '\'')
		{
			len = len + str_replace_len(token, &s[i - 1], NULL, c);
			while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
				|| (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
				i++;
		}
	}
	return (len);
}

void	str_copy_chars_token(t_token *token, char **dst, char c)
{
	if ((token->str[0] != '"' && token->str[0] != '\'' && token->str[0] != '$')
		|| (token->str[0] == '$' && c == '\'') || ((token->str[0] == '"'
				|| token->str[0] == '\'') && (c == '\'' || c == '"')))
	{
		**dst = token->str[0];
		(*dst)++;
	}
	else if (token->str[0] == '$' && c != '\'')
	{
		*dst = *dst + str_replace_len(token, token->str, dst, c);
		if(token->str[1] == '$')
			return (token_move_one_char(token));
		while ((token->str[1] >= 'a' && token->str[1] <= 'z')
			|| token->str[1] == '_'
			|| (token->str[1] >= 'A' && token->str[1] <= 'Z')
			|| (token->str[1] >= '0' && token->str[1] <= '9'))
			token_move_one_char(token);
	}
}

void	str_copy_chars(t_token *token, char *dst)
{
	char	c;

	c = ' ';
	while (((token->str[0] != ' ' && token->str[0] != '<'
				&& token->str[0] != '>') || c == '"' || c == '\'')
		&& 0 < token->strlen)
	{
		if (c != '\'' && c != '"')
			c = ' ';
		else if (c == token->str[0])
			c = token->str[1];
		str_copy_chars_token(token, &dst, c);
		if (c == ' ')
			c = token->str[0];
		token_move_one_char(token);
	}
}

char	*str_copy(t_token *token)
{
	char	*str;
	int		i;

	while (token->str[0] == ' ')
		(token->str)++;
	i = str_get_malloc_len(token, token->str, token->strlen, ' ');
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		exit(-1); //TODO error handling
	str[i] = '\0';
	str_copy_chars(token, str);
	return (str);
}
