#ifndef COMMAND_H
# define COMMAND_H

/*
 * Represents a command. Contains the path to the input file, the path to the
 * output file and the command with its arguments.
 */
typedef struct s_cmd {
	char	*in_file;
	char	*out_file;
	char	**cmd;
}	t_cmd;

/*
 * Allocates a new command object. Returns either the newly allocated object or
 * null if the allocation failed.
 */
struct s_cmd	*cmd_new(void);

/*
 * Initializes the given command object. Does nothing if no object is given.
 */
void			cmd_create(struct s_cmd *self);

/*
 * Deinitializes the given command object. Does nothing if no object is given.
 */
void			cmd_destroy(struct s_cmd *self);

/*
 * Destroys and frees the given command object. Does nothing if no object is
 * given.
 */
void			cmd_delete(struct s_cmd *self);

#endif
