/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:28:38 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/12 15:03:06 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

static int		ft_upper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

static char		ft_isalpha_num(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

char			*ft_strcapitalize(char *str)
{
	int i;
	int space;

	space = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_lower(str[i]) && space == 0)
			str[i] = str[i] - 'a' + 'A';
		else if (ft_upper(str[i]) && space == 1)
			str[i] = str[i] - 'A' + 'a';
		if (ft_isalpha_num(str[i]))
			space = 1;
		else
			space = 0;
		i++;
	}
	return (str);
}
