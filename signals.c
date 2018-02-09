#include "ft_select.h"

/**********************SIGNALS*******************************/
/* SIGINT = ctrl + c (interruption);                        */
/* SIGWINCH = manage window size;                           */
/* SIGSTP = ctrl +z (pause, stop);                          */
/* SIGCONT = continue process (fg);                         */
/* SIGQUIT = ctrl + \ ('*' on azerty)(terminal quit);       */
/************************************************************/

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
	g_act.tmp = morespaces(&g_act);
	g_size = window_size();
	g_act.len = wordbyline(&g_size, &g_act);
	manage_size(&g_act, g_act.tmp, g_act.len, &g_size);
}

void		sig_size(int sig)
{
	(void)sig;
	tputs(tgetstr("cl", NULL), 0, ft_outc);
	g_act.tmp = morespaces(&g_act);
	g_size = window_size();
	g_act.len = wordbyline(&g_size, &g_act);
	manage_size(&g_act, g_act.tmp, g_act.len, &g_size);
}

void			sigtest(void)
{
	signal(SIGINT, sig_int);
	signal(SIGTSTP, sig_tstp);
	signal(SIGCONT, sig_cont);
	signal(SIGQUIT, sig_int);
	signal(SIGWINCH, sig_size);
}