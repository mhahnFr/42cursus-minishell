/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 03:13:32 by mnies             #+#    #+#             */
/*   Updated: 2022/01/29 11:18:54 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_special_cases(char next_char, char **ret, char *sign)
{
	int	i;
	int	num = 100;
	char	*test = "100";

	i = 0;
	if (next_char == '?' && ret == NULL)
	{
		while (num != 0)
		{
			num = num % 10;
			i++;
		}	
	}
	else if (next_char == '?' && ret != NULL)
	{
		*ret = test;
		return (1);	// if (next_char == '?') TODO handle
	}
	else if (next_char != '?' && ret == NULL)
		return (1);
	else if (ret != NULL)
		*ret = sign;
	return (i);
}

size_t	str_get_var(char *str, char **ret)
{
	int		i;
	char	*temp;

	i = 0;
	while ((str[i] >= 'a' && str[i] <= 'z') || str[i] == '_'
		|| (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i == 0)
		return (str_special_cases(str[i], ret, "$"));
	temp = malloc(sizeof(char) * (i + 1));
	if (temp == NULL)
		return (-1); //TODO error handling
	temp[i] = '\0';
	while (i > 0)
	{
		i--;
		temp[i] = str[i];
	}
	str = getenv(temp);
	while ((str[i] != '\0' && ret == NULL) || (temp[i] != '\0' && ret != NULL))
		i++;
	if (ret != NULL)
		*ret = str;
	free(temp);
	return (i);
}

void	str_move(char *ret, char *str, char **tmp, char mode)
{
	while ((*str != ' ' || mode == '"' || mode == '\'') && *str != '\0')
	{
		if (mode != '\'' && mode != '"')
			mode = *str;
		else if (mode == *str)
			mode = *(str + 1);
		if ((*str != '"' && *str != '\'' && *str != '$')
			|| (*str == '$' && mode == '\''))
		{
			*ret = *str;
			ret++;
		}
		else if (*str == '$' && mode != '\'')
		{
			str = str + str_get_var(str + 1, tmp);
			while (tmp != NULL && *tmp != NULL && **tmp != '\0')
			{
				*ret = **tmp;
				ret++;
				(*tmp)++;
			}
		}
		str++;
	}
}

int	str_get_malloc_len(char *str)
{
	char	c;
	int		len;

	c = ' ';
	len = 0;
	while ((*str != ' ' || c == '"' || c == '\'') && *str != '\0')
	{
		if (c != '\'' && c != '"')
			c = *str;
		else if (c == *str)
			c = *(str + 1);
		if ((*str != '"' && *str != '\'' && *str != '$')
			|| (*str == '$' && c == '\''))
			len++;
		else if (*str == '$' && c != '\'')
		{
			len = len + str_get_var(str + 1, NULL);
			while ((str[1] >= 'a' && str[1] <= 'z') || str[1] == '_'
				|| (str[1] >= 'A' && str[1] <= 'Z')
				|| (str[1] >= '0' && str[1] <= '9'))
				str++;
		}
		str++;
	}
	return (len);
}

char	*str_copy(char *str)
{
	char	*ret;
	char	*tmp;
	char	mode;
	int		i;

	mode = ' ';
	tmp = NULL;
	while (*str == ' ')
		str++;
	i = str_get_malloc_len(str);
	if (i == 0)
		return (NULL);
	ret = malloc(sizeof(char) * (i + 1));
	if (ret == NULL)
		return (NULL); //TODO error handling
	ret[i] = '\0';
	str_move(ret, str, &tmp, ' ');
	return (ret);
}
