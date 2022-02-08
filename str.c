#include <stdlib.h>

#include "token.h"
#include "env.h"
#include "str.h"

int	str_replace_len(char **env, char *s, char **dst, char c)
{
	int		i;
	char	*str;
	int		j;

	if (s[0] == '*')
		return (str_wildcard(s, dst, c));
	if (s[0] == '$' && s[1] == '?')
		return (str_wildcard(s, dst, c)); // TODO replace history func
	i = 1;
	while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A'
			&& s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
		i++;
	if (i == 1 && dst != NULL)
		**dst = '$';
	if (i == 1)
		return (1);
	str = get_envar(env, s, &i, c);
	j = 0;
	while (dst != NULL && j != i)
	{
		(*dst)[j] = str[j];
		j++;
	}
	return (i);
}

int	str_get_malloc_len(char **env, char *s, int strlen, char c)
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
			|| (s[i - 1] == '$' && c == '\''))
			len++;
		else if ((s[i - 1] == '$' || s[i - 1] == '*') && c != '\'')
		{
			len = len + str_replace_len(env, &s[i], NULL, c);
			while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
				|| (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
				i++;
		}
	}
	return (len);
}

void	str_copy_chars_token(t_token *token, char **dst, char c)
{
	if ((token->str[0] != '"' && token->str[0] != '\''
			&& token->str[0] != '$') || (token->str[0] == '$' && c == '\''))
	{
		**dst = token->str[0];
		(*dst)++;
	}
	else if ((token->str[0] == '$' || token->str[0] == '*') && c != '\'')
	{
		*dst = *dst + str_replace_len(token->envp, token->str, dst, c);
		while ((token->str[1] >= 'a' && token->str[1] <= 'z')
			|| token->str[1] == '_'
			|| (token->str[1] >= 'A' && token->str[1] <= 'Z')
			|| (token->str[1] >= '0' && token->str[1] <= '9'))
			token_move_one_char(token);
	}
}

void	str_copy_chars(t_token *token, char *dst, int strlen, int suffixlen)
{
	char	c;

	c = ' ';
	while (strlen != 1 && suffixlen != 0)
	{
		dst[strlen - 1] = token->c_args[0][strlen - 2];
		strlen--;
		dst[0] = '/';
	}
	while (((token->str[0] != ' ' && token->str[0] != '<'
				&& token->str[0] != '>') || c == '"' || c == '\'')
		&& 0 < token->strlen && suffixlen == 0)
	{
		if (c != '\'' && c != '"')
			c = token->str[0];
		else if (c == token->str[0])
			c = token->str[1];
		str_copy_chars_token(token, &dst, c);
		token_move_one_char(token);
	}
}

char	*str_copy(t_token *token, int suffixlen)
{
	char	*str;
	int		i;

	if (suffixlen != 0)
	{
		i = 0;
		while (token->c_args[0][i] != '\0')
			i++;
		i = i + 1 + suffixlen;
	}
	else
	{
		while (token->str[0] == ' ')
			(token->str)++;
		i = str_get_malloc_len(token->envp, token->str, token->strlen, ' ');
	}
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		exit(-1); //TODO error handling
	str[i] = '\0';
	str_copy_chars(token, &str[suffixlen], i - suffixlen, suffixlen);
	return (str);
}
