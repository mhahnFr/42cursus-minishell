#ifndef EXIT_H
# define EXIT_H

# include "token.h"

/*
 * Exits the shell. Uses the exit status of the last executed command if no
 * arguments are given. Otherwise, the arguments are converted to an exit
 * status. If an error occures, the appopriate status is returned and the shell
 * will not be exited.
 */
int	builtin_exit(char **argv, t_token *token);

#endif
