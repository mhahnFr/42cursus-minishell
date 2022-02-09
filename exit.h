#ifndef EXIT_H
# define EXIT_H

#include "token.h"

int	builtin_exit(char **argv);

/*
 * This function does not return. After being invoked, everything still being
 * allocated is freed and the application is exited using the exit status
 * indicated in the given token.
 */
void	builtin_prompt_exit(t_token *token);

#endif
