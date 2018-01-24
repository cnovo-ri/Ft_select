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

	act.cmstr = tgetstr("cm", NULL);
	act.clstr = tgetstr("cl", NULL);
	act.invis = tgetstr("vi", NULL);
	act.normal = tgetstr("ve", NULL);
	act.home = tgetstr("ho", NULL);
	return (act);
}

t_size					window_size(void)
{
	struct winsize	w;
	t_size			size;

	ioctl(STDOUT_FILENO,TIOCGWINSZ, &w);
	size.lin = w.ws_row;
	size.col = w.ws_col;
/*	printf("lines %d\n", size.lin);
	printf("columns %d\n", size.col);
*/	return(size);
}

int					lenmax_str(char **argv)
{
	int			len;
	int			i;

	len = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > len)
			len = ft_strlen(argv[i]);
		i++;
	}
	return (len);
}

int				wordbyline(t_size *size, char **argv)
{
//	t_size	size;
	int		sizemax;
	int		wordbyline;

	printf("lines %d\n", size->lin);
	printf("columns %d\n", size->col);
	sizemax = lenmax_str(argv);
	wordbyline = size->col / (sizemax + 5);
	return (wordbyline);
}
