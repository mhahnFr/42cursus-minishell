#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "str.h"
#include "token.h"

void	file_open(t_token *token)
{
	int		i;
	char	*filestr;

	token_move_one_char(token);
	filestr = str_copy(token);
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
	filestr = str_copy(token);
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
	filestr = str_copy(token);
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

void	file_heredoc(t_token *token)
{
	t_heredoc	*tmp;

	token_move_one_char(token);
	token_move_one_char(token);
	while (token->str[0] == ' ')
		token_move_one_char(token);
	while (token->str[0] != '\0' && token->str[0] != ' ' && token->str[0] != '|'
		&& token->str[0] != ')' && token->str[0] != '&')
		token_move_one_char(token);
	if (token->fdin != -1)
		close(token->fdout);
	token->fdin = token->heredoc->fd;
	tmp = token->heredoc;
	token->heredoc = token->heredoc->next;
	free(tmp);
}
