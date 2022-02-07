/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:44:19 by mnies             #+#    #+#             */
/*   Updated: 2022/02/07 12:28:23 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

#include "libft.h"

#include "minishell.h"
#include "syntax.h"

int	syntax_quotation_marks(char *string)
{
	int		i;
	char	cha;

	i = 0;
	while (string[i] != '\0')
	{
		cha = string[i];
		if (cha == '\'' || cha == '\"')
		{
			i++;
			while (string[i] != cha)
			{
				if (string[i] == '\0')
					return (-1);
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	syntax_parenthesis(char *str)
{
	int		i;
	char	c;
	int		open;

	i = 0;
	open = 0;
	while (str[i] != '\0' && open >= 0)
	{
		if (i != 0 && c == str[i] && (c == '\'' || c == '"'))
			c = 'c';
		else
			c = str[i];
		i++;
		while ((str[i] != c && (c == '\'' || c == '"')) || str[i] == ' ')
			i++;
		if ((c != '|' && c != '&' && c != '(' && str[i] == '(') || (c == ')'
				&& str[i] != '|' && str[i] != '&' && str[i] != ')'
				&& str[i] != '\0'))
			return (-1);
		if (c == '(')
			open++;
		else if (c == ')')
			open--;
	}
	return (open);
}

int	syntax_guillemets(char *string)
{
	int		i;
	char	cha;

	i = 0;
	while (string[i] != '\0')
	{
		cha = string[i];
		if (cha == '\'' || cha == '\"')
			while (string[i + 1] != cha)
				i++;
		if (cha == '\'' || cha == '"' || cha == '<' || cha == '>')
			i++;
		if (cha == '<' || cha == '>')
		{
			if (string[i] == cha)
				i++;
			while (string[i] == ' ')
				i++;
			if (string[i] == '<' || string[i] == '>' || string[i] == '\n'
				|| string[i] == '\0' || string[i] == '|' || string[i] == '&')
				return (-1);
		}
		i++;
	}
	return (0);
}

int	syntax_followup(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '|' || str[i] == '&')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '|' || str[i] == '&' || str[i] == '(')
		{
			i++;
			if (str[i] != '&' && str[i - 1] == '&')
				return (-1);
			if ((str[i] == '|' || str[i] == '&') && str[i + 1] != str[i])
				i++;
			while (str[i] == ' ')
				i++;
			if (str[i] == '|' || str[i] == '&'
				|| str[i] == '\n' || str[i] == '\0' || str[i] == ')')
				return (-1);
		}
		i++;
	}
	return (0);
}

int	syntax_check(char *str)
{
	int	i;

	i = 0;
	while (str[0] == ' ')
		str++;
	if (syntax_quotation_marks(str) == -1)
		i = -1;
	else if (syntax_parenthesis(str) != 0)
		i = -1;
	else if (syntax_guillemets(str) == -1)
		i = -1;
	else if (syntax_followup(str) == -1)
		i = -1;
	if (i == -1)
		ft_putendl_fd(NAME ": syntax error", 2);
	return (i);
}
