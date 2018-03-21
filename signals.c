/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:23 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/03/21 00:06:52 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**SIGINT = ctrl + c (interruption);
**SIGWINCH = manage window size;
**SIGSTP = ctrl +z (pause, stop);
**SIGCONT = continue process (fg);
**SIGQUIT = ctrl + \ ('*' on azerty)(terminal force quit);
**SIGTERM = intercept kill signal;
*/

void		sig_int(int sig)
{
	(void)sig;
	tputs(tgetstr("te", NULL), 0, ft_outc);
	tputs(tgetstr("ve", NULL), 0, ft_outc);
	tcsetattr(0, 0, &g_act.saved_term);
	exit(1);
}

void		sig_tstp(int sig)
{
	(void)sig;
	tputs(tgetstr("ve", NULL), 0, ft_outc);
	tputs(tgetstr("te", NULL), 0, ft_outc);
	tcsetattr(0, TCSANOW, &g_act.saved_term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, "\032");
}

void		sig_cont(int sig)
{
	(void)sig;
	signal(SIGTSTP, &sig_tstp);
	init(&g_act.saved_term);
	tputs(tgetstr("ti", NULL), 0, ft_outc);
	tputs(tgetstr("cl", NULL), 0, ft_outc);
	tputs(tgetstr("vi", NULL), 0, ft_outc);
	g_act.tmp = g_act.s_argv;
	g_size = window_size();
	g_act.len = wordbyline(&g_size, &g_act);
	manage_size(&g_act, g_act.tmp, g_act.len, &g_size);
}

void		sig_size(int sig)
{
	(void)sig;
	tputs(tgetstr("cl", NULL), 0, ft_outc);
	g_act.tmp = g_act.s_argv;
	g_size = window_size();
	g_act.len = wordbyline(&g_size, &g_act);
	manage_size(&g_act, g_act.tmp, g_act.len, &g_size);
}

void		sigtest(void)
{
	int		i;

	i = 1;
	while (i < 16)
	{
		signal(i, sig_int);
		i++;
	}
	signal(SIGTSTP, sig_tstp);
	signal(SIGCONT, sig_cont);
	signal(SIGWINCH, sig_size);
}
