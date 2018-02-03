#include "ft_select.h"

int					ft_outc(int c)
{
	ft_putchar(c);
	return (0);
}

int					default_shell(void)
{
	struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
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

t_size					window_size(void)
{
	struct winsize	w;
	t_size			size;

	ioctl(STDOUT_FILENO,TIOCGWINSZ, &w);
	size.lin = w.ws_row;
	size.col = w.ws_col;
	return(size);
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
