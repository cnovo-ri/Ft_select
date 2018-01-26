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
	printf(BLUE"lines %d\n", size.lin);
	printf("columns %d\n"NORMAL, size.col);
	return(size);
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

int					tablen(char **argv)
{
	int		i;

	i = 0;
	if (!(argv))
		return (0);
	while (argv[i])
		i++;
	return (i);
}

char				**morespaces(char **argv)
{
	char	**tmp;
	char	*str;
	int		tab_len;
	t_size	size;
	int		i;
	int		j;

	i = 1;
	tab_len = tablen(argv);
	if (!(tmp = (char **)malloc(sizeof(char *) * (tab_len + 1))))
		return (NULL);
	while (argv[i])
	{
		j = 0;
		size.spaces = lenmax_str(argv) - ft_strlen(argv[i]);
		if (!(str = (char *)malloc(sizeof(char) * size.spaces)))
			return (NULL);
		while (j < (size.spaces))
		{
			str[j] = ' ';
			j++;
		}
		str[j] = '\0';
		tmp[i] = ft_strjoin(argv[i], str);
		free(str);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int				wordbyline(t_size *size, char **argv)
{
	int		sizemax;
	int		wordbyline;

	printf("lines %d\n", size->lin);
	printf("columns %d\n", size->col);
	sizemax = lenmax_str(argv);
	wordbyline = size->col / (sizemax + 5);
	return (wordbyline);
}
