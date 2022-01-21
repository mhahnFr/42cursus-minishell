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
				{
					write(2, "minishell: synatx error\n", 24);
					return (-1);
				}
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
	if (open != 0)
		write(2, "minishell: synatx error\n", 24);
	else
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
			if (string[i] == '<' || string[i] == '>' || string[i] == '\n' || string[i] == '\0')
			{
				write(2, "minishell: synatx error\n", 24);
				return(-1);
			}
		}
		i++;
	}
	return (0);
}


int	syntax_check(char *string)
{
	if (syntax_quotation_marks(string) == -1)
		return (-1);
	if (syntax_parenthesis(string) == -1)
		return (-1);
	if (syntax_guillemets(string) == -1)
		return (-1);
	return (0);
}