/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhahn <mhahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:02:27 by mhahn             #+#    #+#             */
/*   Updated: 2022/02/15 20:02:53 by mhahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "token.h"

void	tokenizer_apply_or_and_2(t_token *token, int pos)
{
	token->strlen = (pos - 1);
	if (pos != 0)
	{
		if (token->fdin == -1)
			token->tmp_fdin = -1;
		else
			token->tmp_fdin = dup(token->fdin);
		if (token->fdout == -1)
			token->tmp_fdout = -1;
		else
			token->tmp_fdout = dup(token->fdout);
	}
}
