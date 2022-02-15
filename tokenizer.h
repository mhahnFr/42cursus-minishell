/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:02:27 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:02:53 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "token.h"

/*
 * Splits the token string into parts and does a reverse call until
 * no more splitting is needed it then runs the commands.
 * Returns 1 for split or succesfulls run.
 * Returns 0 for failed comand run.
 */
int	tokenizer_func(t_token *token);

#endif
