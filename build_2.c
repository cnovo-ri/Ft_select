/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:01 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/03/21 08:44:01 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			arrows_2(t_act *act, int len, char **tmp, int n)
{
	if (act->buf[0] == 27 && act->buf[2] == 68)
	{
		tputs(act->clstr, 0, ft_outc);
		act->cursor--;
		act->cursor = (act->cursor <= 0) ? tablen(act) - 1 : act->cursor;
		while (act->status[act->cursor] == 5)
		{
			act->cursor--;
			act->cursor = (act->cursor <= 0) ? tablen(act) - 1 : act->cursor;
		}
		if (!n)
			ft_putstr_fd("Woooow your test is too big for me !\n", 0);
		else
			act->cursor = print(len, tmp, act);
	}
}

static void			arrows(t_act *act, int len, char **tmp)
{
	int		n;

	n = check_big(n, act);
	if (act->buf[0] == 27 && act->buf[2] == 67)
	{
		tputs(act->clstr, 0, ft_outc);
		act->cursor++;
		act->cursor = (act->cursor >= tablen(act)) ? 1 : act->cursor;
		while (act->status[act->cursor] == 5)
		{
			act->cursor++;
			act->cursor = (act->cursor >= tablen(act)) ? 1 : act->cursor;
		}
		if (!n)
			ft_putstr_fd("Woooow your test is too big for me !\n", 0);
		else
			act->cursor = print(len, tmp, act);
	}
	arrows_2(act, len, tmp, n);
}

static int			delete(t_act *act, int i, int cnt)
{
	if ((act->buf[0] == 27 && act->buf[2] == 51) || act->buf[0] == 127)
	{
		act->status[act->cursor] = 5;
		while (act->status[act->cursor] == 5)
			act->cursor++;
		if (act->cursor >= tablen(act) && act->status[1] != 5)
			act->cursor = 1;
		else
		{
			if (act->cursor >= tablen(act))
				act->cursor = 1;
			while (act->status[act->cursor] == 5)
				act->cursor++;
		}
		i = 0;
		while (g_act.s_argv[i])
		{
			cnt = (act->status[i] == 0 || act->status[i] == 1) ? cnt + 1 : cnt;
			i++;
		}
		if (!(g_act.s_argv[1]) || cnt == 1)
			return (-1);
	}
	return (0);
}

static int			spc_and_dlt(t_act *act, char **tmp, int argc, int len)
{
	int		count;
	int		i;

	count = 0;
	if (act->buf[0] == 32)
	{
		act->status = stck_stat(tmp, argc, act);
		act->cursor++;
		while (act->status[act->cursor] == 5)
			act->cursor++;
		if (act->cursor >= tablen(act) && act->status[1] != 5)
			act->cursor = 1;
		else
		{
			act->cursor = (act->cursor >= tablen(act)) ? 1 : act->cursor;
			while (act->status[act->cursor] == 5)
				act->cursor++;
		}
	}
	if (delete(act, i, count) == -1)
		return (-1);
	arrows(act, len, tmp);
	return (0);
}

int					show_arrow(t_act *act, int argc)
{
	t_size		size;

	act->cursor = 1;
	if (!(act->status = (int *)malloc(sizeof(int) * (argc + 1))))
		return (-1);
	while (!(act->buf[0] == 27 && act->buf[2] == 0))
	{
		if (spc_and_dlt(act, act->tmp, argc, act->len) == -1)
			return (0);
		if (act->buf[0] == 10)
			return (1);
		if (act->buf[0] == 27 && act->buf[2] == 0)
			return (0);
		tputs(act->clstr, 0, ft_outc);
		act->tmp = g_act.s_argv;
		size = window_size();
		act->len = wordbyline(&size, act);
		manage_size(act, act->tmp, act->len, &size);
		g_act.cursor = act->cursor;
		g_act.status = act->status;
		ft_bzero(act->buf, 3);
		read(0, act->buf, 3);
	}
	return (0);
}
