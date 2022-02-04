#include <stddef.h>
#include <stdlib.h>

#include "utils.h"

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

void	utils_free_double_pointer(char ***double_pointer)
{
	int	i;

	i = 0;
	while (*double_pointer != NULL && (*double_pointer)[i] != NULL)
	{
		free((*double_pointer)[i]);
		i++;
	}
	if (*double_pointer != NULL)
		free(*double_pointer);
	*double_pointer = NULL;
}
