/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:57 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:08 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "token.h"

/*
 * Parses the line indicated in the given token until the next block end is
 * reached.
 */
int	parse_func(t_token *token);

#endif
