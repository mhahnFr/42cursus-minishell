/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:02:06 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:23:09 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "token.h"

int	str_wildcard(char *s, char **dst, char c)
{
	(void) s;
	(void) dst;
	(void) c;
	return (0);
}

void	str_move_j(int *j, char *s)
{
	(*j)++;
	if (s[(*j) - 1] == '$')
		while ((s[(*j)] >= 'a' && s[(*j)] <= 'z') || (s[(*j)] >= 'A'
				&& s[(*j)] <= 'Z')
			|| (s[(*j)] >= '0' && s[(*j)] <= '9') || s[(*j)] == '_')
			(*j)++;
}

int	str_exitstat(t_token *token, char **dst)
{
	int	temp;
	int	n;
	int	len;

	n = token->exitstat;
	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	temp = len;
	while (len != 0 && dst != NULL)
	{
		len--;
		(*dst)[len] = n % 10 + '0';
		n = n / 10;
	}
	if (dst == NULL)
		return (temp);
	token_move_one_char(token);
	return (temp);
}

// void str_check_match(filestr, wildstr)
