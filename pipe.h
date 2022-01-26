#ifndef PIPE_H
# define PIPE_H

# include "token.h"
# include "tokenizer.h"

/*
 * Checks if string has a pipe in current priority
 * returns 0 if no pipe found or a positive intiger with
 * position of pipe in string
 */
int	pipe_check(t_token *token);

/*
 * Pipes two part of a string that is already confirmed to have
 * a pipe in right priority forks into child procceses
 * and run sort_func on them
 * returns 1 for succesfull execution of second pipe part and 0 for failure
 */
int	pipe_func(t_token *token);

#endif