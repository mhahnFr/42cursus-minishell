#ifndef TOKEN_H
# define TOKEN_H

typedef struct s_heredoc {
	int					fd;
	struct s_heredoc	*next;
}				t_heredoc;

typedef struct s_token {
	char			*str;
	int				strlen;
	int				exitstat;
	char			**c_args;
	char			**envp;
	char			*lptr;
	int				fdin;
	int				fdout;
	t_heredoc		*heredoc;
}				t_token;

/*
 * Fills heredoc list
 */
t_heredoc	*token_get_heredocs(char *str);

/*
 * Removes heredoc from heredoc list
 * i == 0 -> removes at the beginning
 * i != 0 -> removes at the end
 */
void		token_remove_heredoc(t_token *token, int i);

/*
 * Moves pointer for one char
 */
void		token_move_one_char(t_token *token);

#endif
