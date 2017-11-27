/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:53:47 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/06 15:03:42 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int k;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		k = 0;
		while (little[k] == big[i + k])
		{
			if (little[k + 1] == '\0')
				return ((char *)big + i);
			k++;
		}
		i++;
	}
	return (NULL);
}
