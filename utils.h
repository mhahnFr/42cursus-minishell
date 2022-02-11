#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

# include "token.h"

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
 * Frees token. Everything ther has to be allocated with
 * malloc to avoid freeing unallocated memmory.
 */
int		utils_free_token(t_token *token, int mode);

/*
 * Returns wether the given string represents a valid indentifier. That is, it
 * only contains alphanumeric characters and does not start with a digit. If no
 * string is given, false is returned.
 */
bool	utils_is_identifier(char *string);

/*
 * Compares the two given strings literally. If one of them is null, false is
 * returned, if both are null, true is returned. Otherwise, they are compared.
 */
bool	string_equals(const char *self, const char *other);

/*
 * Allocates a new char array and copys the contents of the environment.
 * Returns either the newly allocated array or null if the allocation failed.
 */
char	**copy_env(void);

#endif
