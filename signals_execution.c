#include <signal.h>

#include "signals.h"

static void	signals_execution_handler(int s)
{
	signal(s, SIG_IGN);
	kill(0, s);
	signal(s, signals_execution_handler);
}

void	signals_execution(void)
{
	signal(SIGINT, signals_execution_handler);
	signal(SIGQUIT, signals_execution_handler);
}
