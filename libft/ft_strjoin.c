/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:00:15 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/05/11 16:43:50 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*destalloc(const char *s1, const char *s2)
{
	char	*dest;
	int		len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	return (dest);
}

static char		*complete(const char *s1, const char *s2)
{
	char	*dest;
	int		i;
	int		k;

	i = 0;
	k = 0;
	dest = destalloc(s1, s2);
	if (dest != '\0')
	{
		while (s1[i] != '\0')
		{
			dest[i + k] = s1[i];
			i++;
		}
		while (s2[k] != '\0')
		{
			dest[i + k] = s2[k];
			k++;
		}
		dest[i + k] = '\0';
		return (dest);
	}
	return (NULL);
}

char			*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = complete(s1, s2);
	return (dest);
}
