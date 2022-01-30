#ifndef TOKEN_H
# define TOKEN_H

/*
 * Represents a token. Consists of a pointer to the next and the previous
 * token, the type and the optional content.
 */
typedef struct s_token {
	char			*str;
	int				strlen;
	char			**c_args;
	char			**envp;
}				t_token;

/*
 * Moves pointer token.str to the next argument
 */
void	token_next_arg(t_token *token);

/*
 * Moves pointer for one char
 */
void	move_one_char(t_token *token);

#endif
