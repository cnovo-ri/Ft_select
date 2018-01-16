/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:42:31 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/01/16 04:29:38 by cnovo-ri         ###   ########.fr       */
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
	return (act);
}
int					show_arrrow(t_act act)
{
	char	buf[3];

	tputs(act.clstr, 0, ft_outc);
	while (1)
	{
/*		ft_putnbr(getchar());
		ft_putchar('\n');
*/		read(0, buf, 3);
		if (buf[0] == 27)
		{
			printf("That's an arrow.\n");
			if (buf[2] == 65)
				printf("Arrow UP\n");
			if (buf[2] == 66)
				printf("Arrow DOWN\n");
			if (buf[2] == 67)
				printf("Arrow RIGHT\n");
			if (buf[2] == 68)
			{
				printf("Arrow LEFT\n");
				tputs(tgoto(act.cmstr, 0, 0), 1, ft_outc);
			}
		}
		else if (buf[0] == 4)
		{
			printf("ctrl + d, exit.\n");
			return (0);
		}
	}
	return (0);
}

int				main(int argc, char **argv)
{
	char			*name_term;
	struct termios	term;

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
	show_arrrow(stock_actions());
	default_shell();
	return(0);
}
