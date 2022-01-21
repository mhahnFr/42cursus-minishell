#include <unistd.h>

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

int	syntax_parenthesis(char *string)
{
	int		i;
	char	cha;
	int		open;

	i = 0;
	open = 0;
	while (string[i] != '\0')
	{
		cha = string[i];
		if (cha == '\'' || cha == '\"')
			while (string[i] != cha)
				i++;
		if (cha == '(')
			open++;
		if (cha == ')')
			open--;
		if (open < 0)
			break ;
		i++;
	}
	if (open == 0)
		return (0);
	return (-1);
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
			while (string[i] != cha)
				i++;
		if (cha == '<' || cha == '>')
		{
			i++;
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

int	syntax_followup(char *string)
{
	int	i;

	if (string[0] == '|' || string[0] == '&')
		return (-1);
	i = 0;
	while (string[i] != '\0')
	{
		if ((string[i] == '|' && string[i + 1] == '|')
			|| (string[i] == '|' && string[i + 1] == ' ')
			|| (string[i] == '&' && string[i + 1] == '&')
			|| (string[i] == '&' && string[i + 1] == ' '))
		{
			i = i + 2;
			while (string[i] == ' ')
				i++;
			if (string[i] == '|' || string[i] == '&'
				|| string[i] == '\n' || string[i] == '\0')
				return (-1);
		}
		i++;
	}
	return (0);
}

int	syntax_check(char *string)
{
	int	i;

	i = 0;
	if (syntax_quotation_marks(string) == -1)
		i = -1;
	if (syntax_parenthesis(string) == -1)
		i = -1;
	if (syntax_guillemets(string) == -1)
		i = -1;
	if (syntax_followup(string) == -1)
		i = -1;
	if (i == -1)
		write(2, "minishell: synatx error\n", 24);
	return (i);
}
