#include <stdlib.h>

#include "command.h"

struct s_cmd	*cmd_new(void)
{
	struct s_cmd	*self;

	self = malloc(sizeof(struct s_cmd));
	if (self != NULL)
		cmd_create(self);
	return (self);
}

void	cmd_create(struct s_cmd *self)
{
	if (self == NULL)
		return ;
	self->in_file = NULL;
	self->out_file = NULL;
	self->cmd = NULL;
}

void	cmd_destroy(struct s_cmd *self)
{
	if (self == NULL)
		return ;
}

void	cmd_delete(struct s_cmd *self)
{
	if (self == NULL)
		return ;
	cmd_destroy(self);
	free(self);
}
