/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:41:23 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/01/17 05:02:33 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "./libft/libft.h"

typedef struct		s_act
{
	char			*clstr;
	char			*invis;
	char			*normal;
	char			*init;
	char			*end;
	int				*status;
	char			**s_argv;
}					t_act;

typedef struct		s_size
{
	unsigned short	lin;
	unsigned short	col;
	unsigned short	lin_tmp;
	unsigned short	col_tmp;
	int				spaces;
}					t_size;

typedef struct		s_var
{
	char			**tmp;
	char			*str;
	int				tab_len;
	t_size			size;
	int				i;
	int				j;
}					t_var;

t_act				g_act;

int					show_arrow(t_act *act, int argc);
char				**delete_arg(int cursor, t_act *act);
int					*stck_stat(char **tmp, int argc, int cursor, t_act *act);
int					print(int len, char **tmp, int cursor, t_act *act);
int					count_space(char *tmp);
char				**morespaces(t_act *act);
int					ft_outc(int c);
int					default_shell(void);
t_act				stock_actions(void);
t_size				window_size(void);
int					lenmax_str(t_act *act);
int					show_arrow(t_act *act, int argc);
int					wordbyline(t_size *size, t_act *act);
int					tablen(t_act *act);

#endif
