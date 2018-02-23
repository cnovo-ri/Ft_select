/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:32 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/02/22 23:44:21 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					ft_outc(int c)
{
	write(0, &c, 1);
	return (0);
}

t_act				stock_actions(void)
{
	t_act	act;

	act.clstr = tgetstr("cl", NULL);
	act.invis = tgetstr("vi", NULL);
	act.normal = tgetstr("ve", NULL);
	act.init = tgetstr("ti", NULL);
	act.end = tgetstr("te", NULL);
	return (act);
}

t_size				window_size(void)
{
	struct winsize	w;
	t_size			size;

	ioctl(0, TIOCGWINSZ, &w);
	size.lin = w.ws_row;
	size.col = w.ws_col;
	g_size.col = size.col;
	g_size.lin = size.lin;
	return (size);
}

int					lenmax_str(t_act *act)
{
	int			len;
	int			i;

	len = 0;
	i = 1;
	while (g_act.s_argv[i])
	{
		if (ft_strlen(g_act.s_argv[i]) > len)
			len = ft_strlen(g_act.s_argv[i]);
		i++;
	}
	return (len);
}

int					check_big(int n, t_act *act)
{
	int		sizemax;
	int		count;

	count = tablen(act);
	sizemax = lenmax_str(act) + 1;
	n = (g_size.col * g_size.lin) / ((sizemax + 1) * (count - 1));
	return (n);
}
