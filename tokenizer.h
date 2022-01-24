#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "token.h"

/*
 * Tokenizes the given string. Returns a linked list containing the recognized
 * tokens. Returns either the allocated list or null in case of any error.
 */
struct s_token	*tokenize(char *string);

#endif
