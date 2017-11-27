/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:11:17 by cnovo-ri          #+#    #+#             */
/*   Updated: 2017/05/08 12:03:59 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*alloc;

	alloc = malloc(size);
	if (alloc == NULL)
		return (NULL);
	ft_memset(alloc, 0, size);
	return (alloc);
}
