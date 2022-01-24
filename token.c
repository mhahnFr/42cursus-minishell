#include <stdlib.h>

#include "token.h"

struct s_token	*token_new(enum e_type type)
{
	struct s_token	*self;

	self = malloc(sizeof(struct s_token));
	if (self != NULL)
		token_create(self, type);
	return (self);
}

void	token_create(struct s_token *self, enum e_type type)
{
	if (self == NULL)
		return ;
	self->type = type;
	self->previous = NULL;
	self->next = NULL;
}

void	token_destroy(struct s_token *self)
{
	if (self == NULL)
		return ;
	self->type = UNDEFINED;
	self->previous = NULL;
	self->next = NULL;
}

void	token_delete(struct s_token *self)
{
	if (self == NULL)
		return ;
	token_destroy(self);
	free(self);
}
