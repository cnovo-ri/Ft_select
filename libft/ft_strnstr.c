/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:53:08 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/06 14:53:50 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	little_len;

	i = 0;
	if (0 == (little_len = ft_strlen(little)))
		return ((char *)big);
	while (*big && (len-- >= little_len))
	{
		if (*big == *little && (0 == ft_memcmp(big, little, little_len)))
			return ((char *)big);
		big++;
		i++;
	}
	return (0);
}
