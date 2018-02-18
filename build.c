/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:42:31 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/02/18 15:17:46 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int						*stck_stat(char **tmp, int argc, t_act *act)
{
	int			i;

	i = 0;
	while (i < argc)
	{
		if (act->status[i] != 1)
			act->status[i] = 0;
		if (i == act->cursor && i != 0)
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

int						init(struct termios *saved_term)
{
	char			*name_term;
	struct termios	term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("Hey, bring back env bro\n", 2);
		return (-1);
	}
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	*saved_term = term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 1;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

static int				actions(int argc, t_act *act)
{
	int		i;

	tputs(act->init, 0, ft_outc);
	tputs(act->clstr, 0, ft_outc);
	tputs(act->invis, 0, ft_outc);
	if (show_arrow(act, argc) == 1)
		i = 1;
	tputs(act->normal, 0, ft_outc);
	tputs(act->end, 0, ft_outc);
	return (i);
}

static void				print_choices(t_act *act, int i)
{
	if (i == 1)
	{
		i = 0;
		while (g_act.s_argv[i])
		{
			if (act->status[i] == 1)
			{
				ft_putstr_fd(g_act.s_argv[i], 1);
				ft_putchar_fd(' ', 1);
			}
			i++;
		}
	}
}

int						main(int argc, char **argv)
{
	t_act			act;
	int				i;

	g_act.s_argv = argv;
	g_act.s_argc = argc;
	if (argc < 2)
	{
		ft_putstr_fd("We need more arguments bro\n", 2);
		return (-1);
	}
	sigtest();
	if (init(&g_act.saved_term) == -1)
		return (-1);
	act = stock_actions();
	i = actions(argc, &act);
	if (i == -1)
		return (-1);
	print_choices(&act, i);
	if (tcsetattr(0, 0, &g_act.saved_term) == -1)
		return (-1);
	return (0);
}
