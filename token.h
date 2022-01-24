#ifndef TOKEN_H
# define TOKEN_H

# include "token_type.h"

/*
 * Represents a token. Consists of a pointer to the next and the previous
 * token, the type and the optional content.
 */
struct s_token {
	enum e_type		type;
	void			*content;
	struct s_token	*previous;
	struct s_token	*next;
};

/*
 * Allocates a new token. Returns either the newly allocated token or null if
 * the allocation failed.
 */
struct s_token	*token_new(enum e_type type);

/*
 * Initializes the given token. Does nothing if no token is given.
 */
void			token_create(struct s_token *self, enum e_type type);

/*
 * Appends the given token to the given list. If no list is given, the token to
 * be appended will be the first element.
 */
void			token_append(struct s_token **self, struct s_token *appendix);

/*
 * Deletes all tokens in the given list of tokens.
 */
void			token_list_delete(struct s_token *self);

/*
 * Deinitializes the given token. Does nothing if no token is given.
 */
void			token_destroy(struct s_token *self);

/*
 * Destroys and frees the given token. Does nothing if no token is given.
 */
void			token_delete(struct s_token *self);

#endif
