#ifndef BUILTIN_H
# define BUILTIN_H

# include "stdbool.h"

# include "token.h"

/*
 * Returns wether the command string of the given token consists of the name of
 * a builtin.
 */
bool	builtin_check(t_token *token);

/*
 * Executes the builtin described by the given token. Returns the exit status
 * of the builtin that was executed. The exit status is stored additionally in
 * the given token.
 */
int		builtin_exec(t_token *token);

#endif
