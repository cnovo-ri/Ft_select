/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:42:31 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/01/17 05:10:11 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_select.h"

static int			count_space(char *tmp)
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

static int				print(int len, char **tmp, int cursor, t_act *act)
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
			if (i == cursor)
			{
				str = ft_strsub(tmp[i], 0, ft_strlen(tmp[i]) -
					count_space(tmp[i]));
				str2 = ft_strchr(tmp[i], ' ');
				if (act->status[i] == 1)
					ft_putstr_fd(RVIDEO, 0);
				ft_putstr_fd(UNDERLINE, 0);
				ft_putstr_fd(str, 0);
				ft_putstr_fd(NORMAL, 0);
				ft_putstr_fd(str2, 0);
				ft_putchar_fd(' ', 0);
			}
			else
			{
				if (act->status[i] == 1)
				{
					str = ft_strsub(tmp[i], 0, ft_strlen(tmp[i]) -
						count_space(tmp[i]));
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
			i++;
			j++;
		}
		ft_putchar_fd('\n', 0);
	}
	return (cursor);
}

static int			*stck_stat(char **tmp, int argc, int cursor, t_act *act)
{
	int			i;

	i = 0;
	while (i < argc)
	{
		if (act->status[i] != 1)
			act->status[i] = 0;
		if (i == cursor && i != 0)
		{
			if (act->status[i] == 1)
				act->status[i] = 0;
			else
				act->status[i] = 1;
		}
		i++;
	}
	act->status[i] = 0;
	i = 0;
	while (i < argc)
	{
		printf("status[%d] : %d\n", i, act->status[i]);
		i++;
	}
	return (act->status);
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
		printf(RED"cursor %d : %s\n"NORMAL, cursor, tmp[cursor]);
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
		if (buf[0] == 27 && buf[1] != '\0')
		{
			if (buf[2] == 67)
			{
				printf("Arrow RIGHT\n");
				tputs(act->clstr, 0, ft_outc);
				cursor++;
				if (cursor >= tablen(act))
					cursor = 1;
				cursor = print(len, tmp, cursor, act);
			}
			if (buf[2] == 68)
			{
				printf("Arrow LEFT\n");
				tputs(act->clstr, 0, ft_outc);
				cursor--;
				if (cursor <= 0)
					cursor = tablen(act) - 1;
				cursor = print(len, tmp, cursor, act);
			}
		}
		if (buf[0] == 10)
			return (1);
		if (buf[0] == 27 && buf[1] == '\0')
		{
			printf("escape, exit.\n");
			return (0);
		}
		ft_bzero(buf, 3);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	char			*name_term;
	char			buffer[2048];
	struct termios	term;
	t_act			act;
	int				i;

	g_act.s_argv = argv;
	if (argc < 2)
	{
		ft_putstr_fd("We need more arguments bro\n", 2);
		return (-1);
	}
	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("Hey, bring back env bro\n", 2);
		return (-1);
	}
	if (tgetent(buffer, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	act = stock_actions();
	tputs(act.init, 0, ft_outc);
	tputs(act.clstr, 0, ft_outc);
	tputs(act.invis, 0, ft_outc);
	printf("test : %s\n", g_act.s_argv[0]);
	if (show_arrow(&act, argc) == 1)
		i = 1;
	tputs(act.normal, 0, ft_outc);
	tputs(act.end, 0, ft_outc);
	if (default_shell() == -1)
		return (-1);
	if (i == 1)
	{
		i = 0;
		while (i < argc)
		{
			if (act.status[i] == 1)
			{
				ft_putstr_fd(g_act.s_argv[i], 1);
				ft_putchar_fd(' ', 1);
			}
			i++;
		}
	}
	return(0);
}
