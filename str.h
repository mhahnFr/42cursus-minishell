#ifndef STR_H
# define STR_H

# include "token.h"

/*
 * Takes a string skips spaces and copies from first non space sign until next
 * whitespace outside of quotation marks and replaces variables if needed
 * suffixlen number of free allocated char before str (e. g. use for cmd path)
 * suffixlen should be 0 if not nedded
 * return str with malloced copy ; if nothing there to copy return is null
 */
char	*str_copy(t_token *token);

int		str_wildcard(char *s, char **dst, char c);

int		str_exitstat(t_token *token, char **dst);

#endif
