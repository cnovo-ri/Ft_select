/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:16 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/03/21 07:35:33 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void				printer_one(char **tmp, int i, t_act *act, int space)
{
	if (act->status[i] != 5)
	{
		if (act->status[i] == 1)
			ft_putstr_fd(RVIDEO, 0);
		ft_putstr_fd(UNDERLINE, 0);
		ft_putstr_fd(tmp[i], 0);
		ft_putstr_fd(NORMAL, 0);
		while (space > 0)
		{
			ft_putchar_fd(' ', 0);
			space--;
		}
		ft_putchar_fd(' ', 0);
	}
}

static void				printer_two(char **tmp, int i, t_act *act, int space)
{
	if (act->status[i] != 5)
	{
		if (act->status[i] == 1)
		{
			ft_putstr_fd(RVIDEO, 0);
			ft_putstr_fd(tmp[i], 0);
			ft_putstr_fd(NORMAL, 0);
			while (space > 0)
			{
				ft_putchar_fd(' ', 0);
				space--;
			}
		}
		else
		{
			ft_putstr_fd(tmp[i], 0);
			while (space > 0)
			{
				ft_putchar_fd(' ', 0);
				space--;
			}
		}
		ft_putchar_fd(' ', 0);
	}
}

int						print(int len, char **tmp, t_act *act)
{
	int			i;
	int			j;
	int			space;

	i = 1;
	while (tmp[i])
	{
		j = 0;
		while (j <= len && tmp[i])
		{
			if (act->status[i] != 5)
			{
				space = lenmax_str(act) - ft_strlen(tmp[i]);
				if (i == act->cursor)
					printer_one(tmp, i, act, space);
				else
					printer_two(tmp, i, act, space);
				j++;
			}
			i++;
		}
		ft_putchar_fd('\n', 0);
	}
	return (act->cursor);
}
