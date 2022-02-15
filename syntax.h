/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:02:18 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:02:55 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

/*
 * Check if string recieved by readline follows the syntax.
 * Returns 0 if syntax ok -1 if not.
 */
int	syntax_check(char *string);

#endif
