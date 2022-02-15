/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:38 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:14 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <stdbool.h>

# include "token.h"

/*
 * Opens fildes for file and sets it to stdin.
 */
void	file_open(t_token *token);

/*
 * Opens fildes for file and sets it to stdout. Overrides thee content of the
 * indicated file.
 */
void	file_write(t_token *token);

/*
 * Opens fildes for file and sets it to stdout. Appends to the contents of the
 * indicated file.
 */
void	file_append(t_token *token);

/*
 * Opens fildes and write user typed content into it.
 */
void	file_heredoc(t_token *token);

#endif
