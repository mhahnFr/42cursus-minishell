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
