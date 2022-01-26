#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>

#include "signals.h"

static void	signals_default_handler(int s)
{
	if (s == SIGINT)
	{
		write(1, "\n", 1);
		//rl_replace_line("", 1);
	}
	rl_on_new_line();
	rl_redisplay();
}

void	signals_default(void)
{
	struct termios	tc;

	signal(SIGINT, signals_default_handler);
	signal(SIGQUIT, signals_default_handler);
	tcgetattr(1, &tc);
	tc.c_lflag = ~ECHOCTL;
	tcsetattr(1, 0, &tc);
}
