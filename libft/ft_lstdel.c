/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:46:41 by cnovo-ri          #+#    #+#             */
/*   Updated: 2016/12/13 16:27:22 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*delete;

	delete = *alst;
	while (delete != NULL)
	{
		del(delete->content, delete->content_size);
		free(delete);
		delete = delete->next;
	}
	*alst = NULL;
}
