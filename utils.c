#include <stddef.h>
#include <stdlib.h>

#include "utils.h"
#include "token.h"

bool	utils_is_whitespace(const char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\b'
		|| c == '\r'
		|| c == '\f'
		|| c == '\a');
}

bool	utils_only_whitespace(const char *string)
{
	size_t	i;

	if (string == NULL)
		return (false);
	i = 0;
	while (string[i] != '\0')
	{
		if (!utils_is_whitespace(string[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	string_equals(const char *self, const char *other)
{
	size_t	i;

	if ((self == NULL && other != NULL)
		|| (other == NULL && self != NULL))
		return (false);
	else if (self == NULL && other == NULL)
		return (true);
	i = 0;
	while (self[i] != '\0' && other[i] != '\0')
	{
		if (self[i] != other[i])
			return (false);
		i++;
	}
	if (self[i] != other[i])
		return (false);
	return (true);
}

int	utils_free_token(t_token *token, int mode)
{
	int	i;

	i = 0;
	while (token->c_args != NULL && token->c_args[i] != NULL)
	{
		free(token->c_args[i]);
		i++;
	}
	if (token->c_args != NULL)
		free(token->c_args);
	token->c_args = NULL;
	if (mode == 1)
		free(token->lptr);
	if (mode == 2 && token->envp != NULL)
	{
		i = 0;
		while (token->envp[i] != NULL)
		{
			free(token->envp[i]);
			i++;
		}
		free(token->envp);
	}
	return (token->exitstat);
}
