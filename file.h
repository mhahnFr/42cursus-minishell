#ifndef FILE_H
# define FILE_H

# include <stdbool.h>

# include "token.h"

/*
 * Opens fildes for file and sets it to stdin
 */
void	file_open(t_token *token);

/*
 * Opens fildes for file and sets it to stdout. Overrides file content
 */
void	file_write(t_token *token);

/*
 * Opens fildes for file and sets it to stdout. Appends file content
 */
void	file_append(t_token *token);

/*
 * Opens fildes and write user typed content into it
 */
void	file_here_document(t_token *token);

#endif