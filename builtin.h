#ifndef BUILTIN_H
# define BUILTIN_H

# include "token.h"

int	builtin_check(t_token *token);

int	builtin_exec(t_token *token);

#endif
