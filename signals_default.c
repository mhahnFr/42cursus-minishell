#include <signal.h>

#include "signals.h"

static void	signals_default_handler(int s)
{
	(void) s;
}

void	signals_default(void)
{
	signal(SIGINT, signals_default_handler);
	signal(SIGQUIT, signals_default_handler);
}
