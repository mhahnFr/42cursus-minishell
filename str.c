/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:02:09 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 22:27:06 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "env.h"
#include "str.h"
#include "token.h"

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

int	str_get_malloc_len(t_token *t, char *s, int m, int len)
{
	int		i;
	int		j;

	j = 0;
	while (((s[j] != ' ' && s[j] != '<' && s[j] != '>') || m == 1)
		&& j < t->strlen)
	{
		i = 0;
		while (m == 0 && s[j] == '\'' && (s[j + i] != '\'' || i == 0))
			i++;
		if (i != 0)
			len = len + i - 1;
		if (s[j] == '"')
			m = !m;
		if (s[j] == '"' || s[j] == '\'')
			j = j + i;
		else if (!(j != 0 && s[j] == '?' && s[j - 1] == '$'))
			len++;
		if (s[j] == '$')
			len = len + str_replace_len(t, &s[j], NULL, '"' - 1 + m) - 1;
		str_move_j(&j, s);
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
		if (token->str[1] == '$')
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
	int		i;

	i = 0;
	c = ' ';
	while (((token->str[0] != ' ' && token->str[0] != '<'
				&& token->str[0] != '>') || c == '"' || c == '\'')
		&& 0 < token->strlen)
	{
		if (c != '\'' && c != '"')
			i = 1;
		else if (c == token->str[0])
			c = token->str[1];
		str_copy_chars_token(token, &dst, c);
		if (i == 1)
			c = token->str[0];
		if (i == 1)
			i = !i;
		token_move_one_char(token);
	}
}

char	*str_copy(t_token *token)
{
	char	*str;
	int		i;

	while (token->str[0] == ' ')
		(token->str)++;
	i = str_get_malloc_len(token, token->str, 0, 0);
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		exit(1);
	str[i] = '\0';
	str_copy_chars(token, str);
	return (str);
}
