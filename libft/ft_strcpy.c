/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:27:45 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/06 13:37:52 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i])
	{
		(((unsigned char *)dst)[i] = ((unsigned char *)src)[i]);
		i++;
	}
	((unsigned char *)dst)[i] = '\0';
	return ((char *)dst);
}
