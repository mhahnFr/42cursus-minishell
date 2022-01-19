#ifndef COMMAND_H
# define COMMAND_H

typedef struct s_cmd {
	char	*in_file;
	char	*out_file;
	char	**cmd;
}	t_cmd;

struct s_cmd	*cmd_new(void);

void			cmd_create(struct s_cmd *self);

void			cmd_destroy(struct s_cmd *self);

void			cmd_delete(struct s_cmd *self);

#endif
