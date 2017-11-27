/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:51:55 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/13 13:10:02 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fresh;

	if (lst)
	{
		if (!(fresh = (t_list*)malloc(sizeof(f(lst)))))
			return (NULL);
		fresh = f(lst);
		fresh->next = ft_lstmap(lst->next, f);
		return (fresh);
	}
	return (NULL);
}
