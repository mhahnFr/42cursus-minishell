/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:57:52 by mnies             #+#    #+#             */
/*   Updated: 2022/02/03 22:10:40 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "token.h"
#include "env.h"
#include "wildcard.h"

// void	str_move(char *ret, char *str, char **tmp, char mode)
// {
// 	while ((*str != ' ' || mode == '"' || mode == '\'') && *str != '\0')
// 	{
// 		if (mode != '\'' && mode != '"')
// 			mode = *str;
// 		else if (mode == *str)
// 			mode = *(str + 1);
// 		if ((*str != '"' && *str != '\'' && *str != '$')
// 			|| (*str == '$' && mode == '\''))
// 		{
// 			*ret = *str;
// 			ret++;
// 		}
// 		else if (*str == '$' && mode != '\'')
// 		{
// 			str = str + str_get_var(str + 1, tmp);
// 			while (tmp != NULL && *tmp != NULL && **tmp != '\0')
// 			{
// 				*ret = **tmp;
// 				ret++;
// 				(*tmp)++;
// 			}
// 		}
// 		str++;
// 	}
// }

int	str_replace_len(char **env, char *s, char **dst, char c)
{
	int		i;
	char	*str;
	int		j;

	if (s[0] == '*')
		return (wildcard(s, dst, c));
	if (s[0] == '$' && s[1] == '?')
		return (wildcard(s, dst, c)); // TODO replace history func
	i = 1;
	while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A'
			&& s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_')
		i++;
	if (i == 1)
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

int	str_get_malloc_len(char **env, char *str, int strlen, char c)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while ((str[i] != ' ' || c == '"' || c == '\'') && i < strlen)
	{
		if (c != '\'' && c != '"')
			c = str[i];
		else if (c == str[i])
			c = str[i + 1];
		if ((str[i] != '"' && str[i] != '\'' && str[i] != '$')
			|| (str[i] == '$' && c == '\''))
			len++;
		else if ((str[i] == '$' || str[i] == '*') && c != '\'')
		{
			len = len + str_replace_len(env, &str[i], NULL, c);
			while ((str[i + 1] >= 'a' && str[i + 1] <= 'z') || str[i + 1] == '_'
				|| (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
				|| (str[i + 1] >= '0' && str[i + 1] <= '9'))
				i++;
		}
		i++;
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
		while ((token->str[0] >= 'a' && token->str[0] <= 'z')
			|| token->str[0] == '_'
			|| (token->str[0] >= 'A' && token->str[0] <= 'Z')
			|| (token->str[0] >= '0' && token->str[0] <= '9'))
			token->str++;
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
	while (suffixlen == 0 && (token->str[0] != ' ' || c == '"' || c == '\'')
		&& 0 < token->strlen)
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
		if (i == 0)
			return (NULL);
	}
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		exit(-1); //TODO error handling
	str[i] = '\0';
	str_copy_chars(token, &str[suffixlen], i - suffixlen, suffixlen);
	return (str);
}
