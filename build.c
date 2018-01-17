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
	act.kustr = tgetstr("ku", NULL);
	act.kdstr = tgetstr("kd", NULL);
	act.klstr = tgetstr("kl", NULL);
	act.krstr = tgetstr("kr", NULL);
	act.home = tgetstr("ho", NULL);
	return (act);
}

int					window_size(void)
{
	struct winsize	w;
	t_size			size;

	ioctl(STDOUT_FILENO,TIOCGWINSZ, &w);
	size.lin = w.ws_row;
	size.col = w.ws_col;
/*	printf("lines %d\n", size.lin);
	printf("columns %d\n", size.col);
*/	return(0);
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

int					show_arrrow(t_act act, int argc, char **argv)
{
	char			buf[3];
	int				i;
	int				len;

	tputs(act.clstr, 0, ft_outc);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
//		ft_putnbr(ft_strlen(argv[i]));
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	len = lenmax_str(argv);
	printf(RVIDEO"lenmax : %d\n"NORMAL, len);
	while (1)
	{
		read(0, buf, 3);
		if (buf[0] == 27 && buf[1] != '\0')
		{
			if (buf[2] == 65)
				printf("Arrow UP\n");
			if (buf[2] == 66)
				printf("Arrow DOWN\n");
			if (buf[2] == 67)
			{
				printf("Arrow RIGHT\n");
//				tputs(act.home, 0, ft_outc);
			}
			if (buf[2] == 68)
			{
				printf("Arrow LEFT\n");
//				tputs(tgoto(act.cmstr, 0, 0), 1, ft_outc);
			}
		}
		else if (buf[0] == 27 && buf[1] == '\0')
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
	struct termios	term;
	
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
	window_size();
	show_arrrow(stock_actions(), argc, argv);
	default_shell();
	return(0);
}
