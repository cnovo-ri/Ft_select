# include "ft_select.h"

int					default_shell(void)
{
	struct termios	term;
	char			*name_term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (-1);
	return (0);
}

int					show_arrrow(void)
{
	char	buf[3];

	while (1)
	{
		ft_putnbr(getchar());
		ft_putchar('\n');
		read(0, buf, 3);
		if (buf[0] == 27)
			printf("Arrow\n");
		else if (buf[0] == 4)
		{
			printf("ctrl + d \n");
			return (0);
		}
	}
	return (0);
}

int					main(int argc, char **argv)
{
	struct termios	term;
	char			*name_term;

	(void)argc;
	(void)argv;
	if (!(name_term = getenv("TERM")))
		return (-1);
	if (!(tgetent(NULL, name_term)))
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	show_arrrow();
	if (default_shell() == -1)
		return (-1);
	return (0);
}
