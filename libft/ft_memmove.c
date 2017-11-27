/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 18:20:38 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/09 16:54:40 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned const char	*source;

	dest = dst;
	source = src;
	if (source <= dest)
	{
		while (len--)
			dest[len] = source[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
