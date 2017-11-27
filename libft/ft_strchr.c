/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:46:40 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/03/09 16:13:23 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t len;

	len = ft_strlen(s);
	if (*s++ == c)
		return ((char *)s - 1);
	while (len--)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
