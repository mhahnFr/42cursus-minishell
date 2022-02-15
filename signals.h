/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:02:03 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:02:59 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

/*
 * Configures the signals for the default behaviour in the main loop.
 */
void	signals_default(void);

/*
 * Configures the signals for the behaviour inside of builtins.
 */
void	signals_builtins(void);

/*
 * Configures the signals for the behaviour when executing childs.
 */
void	signals_execution(void);

/*
 * Resets all signals to the default behaviour.
 */
void	signals_reset(void);

/*
 * Resets the settings for dislaying the signal characters.
 */
void	signals_reset_echoctl(void);

#endif
