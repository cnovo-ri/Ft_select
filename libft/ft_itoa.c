/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:13:28 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/10/11 19:40:31 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_number(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		itoa_neg(char *str, int *n, int *neg)
{
	*n *= -1;
	str[0] = '-';
	*neg = 1;
}

char			*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	neg = 0;
	len = count_number(n);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		itoa_neg(str, &n, &neg);
	while (len >= neg)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}
