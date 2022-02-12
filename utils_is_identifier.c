#include "libft.h"

#include "utils.h"

bool	utils_is_identifier(char *string)
{
	size_t	i;

	if (string == NULL)
		return (false);
	if (ft_isdigit(string[0]))
		return (false);
	i = 0;
	while (string[i] != '\0')
	{
		if (!ft_isalnum(string[i]))
			return (false);
		i++;
	}
	return (true);
}
