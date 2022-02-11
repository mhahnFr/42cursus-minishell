#include <stddef.h>

#include "utils.h"

bool	string_starts_with(const char *self, const char *start)
{
	size_t	i;

	if ((self == NULL && start != NULL)
		|| (self != NULL && start == NULL))
		return (false);
	if (self == NULL && start == NULL)
		return (true);
	i = 0;
	while (self[i] != '\0' && start[i] != '\0')
	{
		if (self[i] != start[i])
			return (false);
		i++;
	}
	if (self[i] == '\0' && start[i] != '\0')
		return (false);
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
