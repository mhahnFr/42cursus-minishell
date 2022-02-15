#ifndef CD_H
# define CD_H

/*
 * Changes the directory to the directory indicated by the first argument. If
 * no arguments are given, the home directory described in the given
 * environment is used. Returns wether the operation was successfull.
 */
int	builtin_cd(char **argv, char **env);

#endif
