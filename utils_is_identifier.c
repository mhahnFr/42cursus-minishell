#include "libft.h"

#include "utils.h"

bool	utils_is_identifier_length(char *string, size_t length)
{
	size_t	i;

	if (string == NULL)
		return (false);
	if (!ft_isalpha(string[0]) && string[0] != '_')
		return (false);
	i = 0;
	while (string[i] != '\0' && i < length)
	{
		if (!ft_isalnum(string[i]) && string[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

bool	utils_is_identifier(char *string)
{
	if (string == NULL)
		return (false);
	return (utils_is_identifier_length(string, ft_strlen(string)));
}
