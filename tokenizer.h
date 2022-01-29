#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "token.h"

/*
 * Splits the token string into parts and does a reverse call until
 * no more splitting is needed it then runs the comands
 * returns 1 for split or succesfulls run 
 * returns 0 for failed comand run
 */
int	tokenizer_func(t_token *token, char **envp);

#endif
