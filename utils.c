#include <stddef.h>

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
