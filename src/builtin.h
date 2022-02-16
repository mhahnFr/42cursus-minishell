/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:59:40 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:37 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "stdbool.h"

# include "token.h"

void	builtin_close_fds(t_token *token, int *i, int *j);

void	builtin_replace_fds(int i, int j);

/*
 * Returns wether the command string of the given token consists of the name of
 * a builtin.
 */
bool	builtin_check(t_token *token);

/*
 * Executes the builtin described by the given token. Returns the exit status
 * of the builtin that was executed. The exit status is stored additionally in
 * the given token.
 */
int		builtin_exec(t_token *token);

#endif
