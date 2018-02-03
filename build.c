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

int				*stck_stat(char **tmp, int argc, int cursor, t_act *act)
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
	return (act->status);
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
	if (show_arrow(&act, argc) == 1)
		i = 1;
	tputs(act.normal, 0, ft_outc);
	tputs(act.end, 0, ft_outc);
	if (default_shell() == -1)
		return (-1);
	if (i == 1)
	{
		i = 0;
		while (g_act.s_argv[i])
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
