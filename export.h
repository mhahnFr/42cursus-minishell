/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:33 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:16 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include "token.h"

/*
 * Exports the given arguments to the arguments indicated in the given token.
 * If no arguments are given, all exported variables are printed to the
 * standard output. Returns 0 if everything worked out, 1 otherwise.
 */
int	builtin_export(t_token *token);

#endif
