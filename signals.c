#include <signal.h>
#include <termios.h>

#include "signals.h"

void	signals_reset(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	signals_reset_echoctl(void)
{
	struct termios	tc;

	tcgetattr(1, &tc);
	tc.c_lflag |= ECHOCTL;
	tcsetattr(1, 0, &tc);
}

void	signals_builtins(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
