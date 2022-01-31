#include <signal.h>
#include <termios.h>
#include <unistd.h>

#include "signals.h"

static void	signals_execution_handler(int s)
{
	signal(s, SIG_IGN);
	kill(0, s);
	signal(s, signals_execution_handler);
	write(1, "\n", 1);
}

void	signals_execution(void)
{
	struct termios	tc;

	signal(SIGINT, signals_execution_handler);
	signal(SIGQUIT, signals_execution_handler);
	tcgetattr(1, &tc);
	tc.c_lflag |= ECHOCTL;
	tcsetattr(1, 0, &tc);
}
