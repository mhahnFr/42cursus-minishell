#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "str.h"
#include "token.h"
#include "libft.h"

void	file_open(t_token *token)
{
	int		i;
	char	*filestr;

	token_move_one_char(token);
	filestr = str_copy(token, 0);
	i = open(filestr, O_RDONLY);
	if (i == -1)
	{
		free(filestr);
		exit(-1); // TODO erro managment
	}
	dup2(i, 0);
	token_next_arg(token);
}

void	file_write(t_token *token)
{
	int		i;
	char	*filestr;

	token_move_one_char(token);
	filestr = str_copy(token, 0);
	i = open(filestr, O_WRONLY | O_CREAT | O_TRUNC, 644);
	if (i == -1)
	{
		free(filestr);
		exit(-1); // TODO erro managment
	}
	dup2(i, 1);
	token_next_arg(token);
}

void	file_append(t_token *token)
{
	int		i;
	char	*filestr;

	token_move_one_char(token);
	token_move_one_char(token);
	filestr = str_copy(token, 0);
	i = open(filestr, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (i == -1)
	{
		free(filestr);
		exit(-1); // TODO erro managment
	}
	dup2(i, 1);
	token_next_arg(token);
}

// void	file_here_document(t_token token)
// {

// }
