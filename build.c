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

static void			first_print(char **argv)
{
	t_size		size;
	int			len;
	int			i;
	int			j;
	
	i = 1;
	size = window_size();
	len = wordbyline(&size, argv);
	while (argv[i])
	{
		j = 0;
		while (j <= len && argv[i])
		{
			ft_putstr(argv[i]);
			ft_putchar(' ');
			i++;
			j++;
		}
		ft_putchar('\n');
	}
}

int					show_arrow(t_act act, int argc, char **argv)
{
	char			buf[3];
	int				i;
	int				j;
	int				len;
	int				flag;
	t_size			size;

	i = 1;
	flag = 0;
	tputs(act.clstr, 0, ft_outc);
	tputs(act.invis, 0, ft_outc);
	first_print(argv);
	while (1)
	{
		if (flag != 0)
		{
			size = window_size();
			len = wordbyline(&size, argv);
		}
		if (flag == 1 && ((size.lin_tmp != size.lin) ||
			(size.col_tmp != size.col)))
		{
			i = 1;
			tputs(act.clstr, 0, ft_outc);
			while (argv[i])
			{
				j = 0;
				while (j <= len && argv[i])
				{
					ft_putstr(argv[i]);
					ft_putchar(' ');
					i++;
					j++;
				}
				ft_putchar('\n');
			}
		}
		flag = 1;
		size.lin_tmp = size.lin;
		size.col_tmp = size.col;
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
			tputs(act.normal, 0, ft_outc);
			return (0);
		}
	/*	if (flag == 1 && ((size.lin_tmp != size.lin) ||
			(size.col_tmp != size.col)))
		{
			i = 1;
			tputs(act.clstr, 0, ft_outc);
			while (argv[i])
			{
				j = 0;
				while (j <= len && argv[i])
				{
					ft_putstr(argv[i]);
					ft_putchar(' ');
					i++;
					j++;
				}
				ft_putchar('\n');
			}
		}
		flag = 1;
		size.lin_tmp = size.lin;
		size.col_tmp = size.col;
	*/	ft_bzero(buf, 3);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	char			*name_term;
	struct termios	term;

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
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	show_arrow(stock_actions(), argc, argv);
	default_shell();
	return(0);
}
