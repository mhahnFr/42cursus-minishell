/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:19 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:34:38 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "token.h"

/*
 * Executes a token that is ready to be executed. The given string is a string
 *  with all the locations where to look for the command separted by a ":".
 *  Returns the status of the execution, which is stored additionally in the
 *  given token.
 */
int	exec_run(t_token *token, char *env);

#endif
