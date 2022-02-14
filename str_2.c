#include <unistd.h>

#include "token.h"

int	str_wildcard(char *s, char **dst, char c)
{
	(void) s;
	(void) dst;
	(void) c;
	return (0);
}

int	str_exitstat(t_token *token, char **dst)
{
	int	temp;
	int	n;
	int	len;

	n = token->exitstat;
	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	temp = len;
	while (len != 0 && dst != NULL)
	{
		len--;
		(*dst)[len] = n % 10 + '0';
		n = n / 10;
	}
	if (dst == NULL)
		return (temp - 1);
	token_move_one_char(token);
	return (temp);
}

// void str_check_match(filestr, wildstr)
