#ifndef PARSE_H
# define PARSE_H

# include "token.h"

/*
 * Parses the line indicated in the given token until the next block end is
 * reached.
 */
int	parse_func(t_token *token);

#endif
