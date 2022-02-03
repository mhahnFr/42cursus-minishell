#ifndef ENV_H
# define ENV_H

/*
 * Displays the environment variables.
 */
int	builtin_env(char **argv, char **env);

char	*get_envar(char **env, char *str, int *strlen, char mode);

#endif
