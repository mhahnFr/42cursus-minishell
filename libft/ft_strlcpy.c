/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnies <mnies@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:32:51 by mhahn             #+#    #+#             */
/*   Updated: 2022/01/20 18:22:47 by mnies            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;

	if (src == NULL || dst == NULL)
		return (0);
	counter = 0;
	if (dstsize > 0)
	{
		while (counter < dstsize - 1 && counter < ft_strlen(src))
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = '\0';
	}
	return (ft_strlen(src));
}
