/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:01 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:30 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ECHO_H
# define ECHO_H

/*
 * Prints all given arguments to the standard output. If the "-n" flag is
 * given, no newline will be printed.
 */
int	builtin_echo(char **argv);

#endif
