/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:00:11 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:01:27 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
 * Displays the environment variables indicated by the given environment.
 */
int		builtin_env(char **argv, char **env);

char	*get_envar(char **env, char *str, int *strlen, char mode);

#endif
