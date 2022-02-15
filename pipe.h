#ifndef PIPE_H
# define PIPE_H

# include "token.h"

/*
 * Checks if string has a pipe in the current priority. Returns 0 if no pipe
 * was found, otherwise a positive integer with the position of the pipe in the
 * string indicated by the given token is returned.
 */
int	pipe_check(t_token *token);

/*
 * Pipes two parts of a string that is already confirmed to have a pipe in the
 * right priority. Forks into child procceses and run sort_func on them.
 * Returns 1 for succesfull execution of second pipe part and 0 for failure.
 */
int	pipe_func(t_token *token);

#endif
