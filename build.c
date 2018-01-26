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

static int			count_space(char *tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] == ' ')
			j++;
		i++;
	}
	return (j);
}
/*ESPACE = 32*/
void				print(int len, char **tmp, char **argv, int cursor)
{
	int			i;
	int			j;
	char		*str;
	char		*str2;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (j <= len && tmp[i])
		{
			if (i == cursor)
			{
				str = ft_strsub(tmp[i], 0, ft_strlen(tmp[i]) -
					count_space(tmp[i]));
				str2 = ft_strchr(tmp[i], ' ');
				ft_putstr(UNDERLINE);
				ft_putstr(str);
				ft_putstr(NORMAL);
				ft_putstr(str2);
				ft_putchar(' ');
			}
			else
			{
				ft_putstr(tmp[i]);
				ft_putchar(' ');
			}
			i++;
			j++;
		}
		ft_putchar('\n');
	}
}

static void				print_rvideo(int len, char **tmp, int cursor)
{
	int			i;
	int			j;
	char		*str;
	char		*str2;

	i = 1;
	while (tmp[i])
	{
		j = 0;
		while (j <= len && tmp[i])
		{
			if (i == cursor)
			{
				str = ft_strsub(tmp[i], 0, ft_strlen(tmp[i]) -
					count_space(tmp[i]));
				str2 = ft_strchr(tmp[i], ' ');
				ft_putstr(RVIDEO);
				ft_putstr(str);
				ft_putstr(NORMAL);
				ft_putstr(str2);
				ft_putchar(' ');
			}
			else
			{
				ft_putstr(tmp[i]);
				ft_putchar(' ');
			}
			i++;
			j++;
		}
		ft_putchar('\n');
	}
}

int					show_arrow(t_act act, int argc, char **argv)
{
	char			**tmp;
	char			buf[3];
	int				cursor;;
	int				len;
	int				flag;
	t_size			size;

	flag = 0;
	cursor = 1;
//	tmp = morespaces(argv);
	while (!(buf[0] == 27 && buf[2] == 0))
	{
/*		tmp = morespaces(argv);
		size = window_size();
		len = wordbyline(&size, argv);
		if (size.lin_tmp && size.col_tmp && ((size.lin_tmp != size.lin) || (size.col_tmp != size.col)))
		{
			size = window_size();
			len = wordbyline(&size, argv);
		}
*/		tputs(act.clstr, 0, ft_outc);
		tmp = morespaces(argv);
		size = window_size();
		len = wordbyline(&size, argv);
		print(len, tmp, argv, cursor);
		flag = 0;
		size.lin_tmp = size.lin;
		size.col_tmp = size.col;
		read(0, buf, 3);
		if (buf[0] == 32)	/*mettre un else if pour les autres keys*/
		{
			tputs(act.clstr, 0, ft_outc);
			//cursor++;
			if (cursor >= tablen(argv))
				cursor = 1;
			print_rvideo(len, tmp, cursor);
		}
		if (buf[0] == 27 && buf[1] != '\0')
		{
			if (buf[2] == 65)
				printf("Arrow UP\n");
			if (buf[2] == 66)
				printf("Arrow DOWN\n");
			if (buf[2] == 67)
			{
				printf("Arrow RIGHT\n");
				tputs(act.clstr, 0, ft_outc);
				cursor++;
				if (cursor >= tablen(argv))
					cursor = 1;
				print(len, tmp, argv, cursor);
			}
			if (buf[2] == 68)
			{
				printf("Arrow LEFT\n");
				tputs(act.clstr, 0, ft_outc);
				cursor--;
				if (cursor <= 0)
				{
					cursor = tablen(argv) - 1;
					printf("cursor : %d\nargc : %d\n", cursor, argc);
				}
				print(len, tmp, argv, cursor);
			}
		}
		if (buf[0] == 27 && buf[1] == '\0')
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
	t_act			act;

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
	act = stock_actions();
	tputs(act.init, 0, ft_outc);
	tputs(act.clstr, 0, ft_outc);
	tputs(act.invis, 0, ft_outc);
	show_arrow(act, argc, argv);
	tputs(act.normal, 0, ft_outc);
	tputs(act.end, 0, ft_outc);
	if (default_shell() == -1)
		return (-1);
	return(0);
}
