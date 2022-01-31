#ifndef EXEC_H
# define EXEC_H

# include <stdbool.h>

# include "token.h"

/*
 * Executes a token that is ready to be executed'
 * env is str with all locations where to look for the command separted by ":"
 * returns status of execution
 */
bool	exec_run(t_token *token, char *env);

#endif
