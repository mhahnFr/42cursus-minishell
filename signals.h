#ifndef SIGNALS_H
# define SIGNALS_H

/*
 * Configures the signals for the default behaviour in the main loop.
 */
void	signals_default(void);

/*
 * Configures the signals for the behaviour inside of builtins.
 */
void	signals_builtins(void);

/*
 * Configures the signals for the behaviour when executing childs.
 */
void	signals_execution(void);

/*
 * Resets all signals to the default behaviour.
 */
void	signals_reset(void);

#endif
