#include "ft_select.h"

char				**delete_arg(int cursor, t_act *act)
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
		if (i != cursor)
		{
			tmp[j] = g_act.s_argv[i];
			j++;
		}
		if (i >= cursor)
			act->status[i] = act->status[i + 1];
		i++;
	}
	tmp[j] = NULL;
	return (tmp);
}

int					show_arrow(t_act *act, int argc)
{
	char			**tmp;
	char			buf[3];
	int				cursor;
	int				len;
	int				sizemax;
	t_size			size;
	
	cursor = 1;
	if (!(act->status = (int *)malloc(sizeof(int) * (argc + 1))))
		return (-1);
	while (!(buf[0] == 27 && buf[2] == 0))
	{
		tputs(act->clstr, 0, ft_outc);
		tmp = morespaces(act);
		size = window_size();
		len = wordbyline(&size, act);
		sizemax = lenmax_str(act) + 1;
		if (sizemax > size.col)
			ft_putstr_fd("Windows size is too small bro\n", 0);
		else
			cursor = print(len, tmp, cursor, act);
		size.lin_tmp = size.lin;
		size.col_tmp = size.col;
		read(0, buf, 3);
		if (buf[0] == 32)
		{
			act->status = stck_stat(tmp, argc, cursor, act);
			cursor++;
			if (cursor >= tablen(act))
					cursor = 1;
		}
		if ((buf[0] == 27 && buf[2] == 51) || buf[0] == 127)
		{
			g_act.s_argv = delete_arg(cursor, act);
			if (cursor >= tablen(act))
				cursor = 1;
			if (!(g_act.s_argv[1]))
				return (0);
		}
		if (buf[0] == 27 && buf[2] == 67)
		{
			tputs(act->clstr, 0, ft_outc);
			cursor++;
			if (cursor >= tablen(act))
				cursor = 1;
			cursor = print(len, tmp, cursor, act);
		}
		if (buf[0] == 27 && buf[2] == 68)
		{
			tputs(act->clstr, 0, ft_outc);
			cursor--;
			if (cursor <= 0)
				cursor = tablen(act) - 1;
			cursor = print(len, tmp, cursor, act);
		}
		if (buf[0] == 10)
			return (1);
		if (buf[0] == 27 && buf[1] == '\0')
			return (0);
		ft_bzero(buf, 3);
	}
	return (0);
}

