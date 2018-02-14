/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:16 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/02/14 17:16:48 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void					printer_one(char **tmp, int i, t_act *act)
{
	char		*str;
	char		*str2;

	str = ft_strsub(tmp[i], 0, ft_strlen(tmp[i]) - count_space(tmp[i]));
	str2 = ft_strchr(tmp[i], ' ');
	if (act->status[i] == 1)
		ft_putstr_fd(RVIDEO, 0);
	ft_putstr_fd(UNDERLINE, 0);
	ft_putstr_fd(str, 0);
	ft_putstr_fd(NORMAL, 0);
	ft_putstr_fd(str2, 0);
	ft_putchar_fd(' ', 0);
}

static void					printer_two(char **tmp, int i, t_act *act)
{
	char		*str;
	char		*str2;

	if (act->status[i] == 1)
	{
		str = ft_strsub(tmp[i], 0, ft_strlen(tmp[i]) - count_space(tmp[i]));
		str2 = ft_strchr(tmp[i], ' ');
		ft_putstr_fd(RVIDEO, 0);
		ft_putstr_fd(str, 0);
		ft_putstr_fd(NORMAL, 0);
		ft_putstr_fd(str2, 0);
	}
	else
		ft_putstr_fd(tmp[i], 0);
	ft_putchar_fd(' ', 0);
}

int						print(int len, char **tmp, t_act *act)
{
	int			i;
	int			j;
	char		*str;
	char		*str2;

	i = 1;
	while (tmp[i])
	{
		j = 0;
		while (j <= len && tmp[i])
		{
			if (i == act->cursor)
				printer_one(tmp, i, act);
			else
				printer_two(tmp, i, act);
			i++;
			j++;
		}
		ft_putchar_fd('\n', 0);
	}
	return (act->cursor);
}
