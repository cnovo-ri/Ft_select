/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:36 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/03/21 01:33:11 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					manage_size(t_act *act, char **tmp, int len, t_size *size)
{
	int		sizemax;
	int		n;
	int		count;

	count = tablen(act);
	sizemax = lenmax_str(act) + 1;
	n = (size->col * size->lin) / ((sizemax + 1) * (count - 1));
	if (!n)
	{
		ft_putstr_fd("Woooow your test is too big for me !\n", 0);
		return (0);
	}
	if (sizemax > size->col)
	{
		ft_putstr_fd("Windows size is too small bro\n", 0);
	}
	else
		act->cursor = print(len, tmp, act);
	return (0);
}

void				free_tab(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

int					tablen(t_act *act)
{
	int		i;

	i = 0;
	if (!(g_act.s_argv))
		return (0);
	while (g_act.s_argv[i])
		i++;
	return (i);
}

int					count_space(char *tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] == ' ')
			j++;
		i++;
	}
	return (j);
}

int					wordbyline(t_size *size, t_act *act)
{
	int		sizemax;
	int		wordbyline;

	sizemax = lenmax_str(act);
	wordbyline = size->col / (sizemax + 5);
	return (wordbyline);
}
