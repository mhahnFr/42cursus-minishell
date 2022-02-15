/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:59:55 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:33 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

/*
 * Changes the directory to the directory indicated by the first argument. If
 * no arguments are given, the home directory described in the given
 * environment is used. Returns wether the operation was successfull.
 */
int	builtin_cd(char **argv, char **env);

#endif
