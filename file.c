#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <termios.h>

#include "str.h"
#include "signals.h"
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
	if (token->fdin != -1)
		close(token->fdin);
	token->fdin = i;
}

void	file_write(t_token *token)
{
	int		i;
	char	*filestr;

	token_move_one_char(token);
	filestr = str_copy(token, 0);
	i = open(filestr, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (i == -1)
	{
		free(filestr);
		exit(-1); // TODO erro managment
	}
	if (token->fdout != -1)
		close(token->fdout);
	token->fdout = i;
}

void	file_append(t_token *token)
{
	int		i;
	char	*filestr;

	token_move_one_char(token);
	token_move_one_char(token);
	filestr = str_copy(token, 0);
	i = open(filestr, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (i == -1)
	{
		free(filestr);
		exit(-1); // TODO erro managment
	}
	if (token->fdout != -1)
		close(token->fdout);
	token->fdout = i;
}

void	file_here_document(t_token *token)
{
	char			*line;
	char			*eof;
	int				pint[2];

	signals_default();
	token_move_one_char(token);
	token_move_one_char(token);
	eof = str_copy(token, 0);
	if (pipe(pint) == -1)
		exit(-1); // TODO FREE TOKEN
	while (1)
	{	
		line = readline(">" " ");
		if (line == NULL || !ft_strncmp(line, eof, ft_strlen(eof) + 1))
			break ;
		write(pint[1], line, ft_strlen(line));
		write(pint[1], "\n", 1);
		free(line);
	}
	close(pint[1]);
	if (token->fdin != -1)
		close(token->fdin);
	token->fdin = pint[0];
	signals_execution();
}
