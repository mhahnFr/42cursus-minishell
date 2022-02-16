/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:04:07 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:04:14 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
 * Returns the next line of the file indicated by the given file descriptor.
 * If nothing else to read is left, or an error occures, null is returned.
 */
char				*get_next_line(int fd);

#endif
