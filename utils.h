#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

/*
 * Returns wether the given character is a whitespace.
 */
bool	utils_is_whitespace(const char c);

/*
 * Returns wether the given string consists only of whitespaces. Returns false
 * if no string is given.
 */
bool	utils_only_whitespace(const char *string);

/*
 * Frees a double pointer to char. Everything ther has to be allocated with
 * malloc to avoid freeing unallocated memmory.
 */
void	utils_free_double_pointer(char ***double_pointer);

/*
 * Allocates a new char array and copys the contents of the environment.
 * Returns either the newly allocated array or null if the allocation failed.
 */
char	**copy_env(void);

#endif
