/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:01 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/02/14 17:16:05 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char				**delete_arg(t_act *act)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tmp = (char **)malloc(sizeof(char *) * (tablen(act) - 1))))
		return (NULL);
	while (g_act.s_argv[i])
	{
		if (i != act->cursor)
		{
			tmp[j] = g_act.s_argv[i];
			j++;
		}
		if (i >= act->cursor)
			act->status[i] = act->status[i + 1];
		i++;
	}
	tmp[j] = NULL;
	return (tmp);
}

static void			arrows(t_act *act, int len, char **tmp)
{
	if (act->buf[0] == 27 && act->buf[2] == 67)
	{
		tputs(act->clstr, 0, ft_outc);
		act->cursor++;
		if (act->cursor >= tablen(act))
			act->cursor = 1;
		act->cursor = print(len, tmp, act);
	}
	if (act->buf[0] == 27 && act->buf[2] == 68)
	{
		tputs(act->clstr, 0, ft_outc);
		act->cursor--;
		if (act->cursor <= 0)
			act->cursor = tablen(act) - 1;
		act->cursor = print(len, tmp, act);
	}
}

static int			spc_and_dlt(t_act *act, char **tmp, int argc, int len)
{
	if (act->buf[0] == 32)
	{
		act->status = stck_stat(tmp, argc, act);
		act->cursor++;
		if (act->cursor >= tablen(act))
			act->cursor = 1;
	}
	if ((act->buf[0] == 27 && act->buf[2] == 51) || act->buf[0] == 127)
	{
		g_act.s_argv = delete_arg(act);
		if (act->cursor >= tablen(act))
			act->cursor = 1;
		if (!(g_act.s_argv[1]))
			return (-1);
	}
	arrows(act, len, tmp);
	return (0);
}

void				manage_size(t_act *act, char **tmp, int len, t_size *size)
{
	int		sizemax;

	sizemax = lenmax_str(act) + 1;
		if (sizemax > size->col)
			ft_putstr_fd("Windows size is too small bro\n", 0);
		else
			act->cursor = print(len, tmp, act);
}

int					show_arrow(t_act *act, int argc)
{
	t_size			size;

	act->cursor = 1;
	if (!(act->status = (int *)malloc(sizeof(int) * (argc + 1))))
		return (-1);
	while (!(act->buf[0] == 27 && act->buf[2] == 0))
	{
		tputs(act->clstr, 0, ft_outc);
		act->tmp = morespaces(act);
		size = window_size();
		act->len = wordbyline(&size, act);
		manage_size(act, act->tmp, act->len, &size);
		g_act.cursor = act->cursor;
		g_act.status = act->status;
		read(0, act->buf, 3);
/*		if (act->buf[0] == 27 && act->buf[1] == '\0')
			return (0);
*/		if (spc_and_dlt(act, act->tmp, argc, act->len) == -1)
			return (0);
		if (act->buf[0] == 10)
			return (1);
		if (act->buf[0] == 27 && act->buf[2] == 0)
			return (0);
		ft_bzero(act->buf, 3);
	}
	return (0);
}
