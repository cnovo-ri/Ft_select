/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 23:41:23 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/03/21 00:50:47 by cnovo-ri         ###   ########.fr       */
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
	char			buf[3];
	int				cursor;
	struct termios	saved_term;
	char			**tmp;
	int				len;
	int				s_argc;
	char			**copy_argv;
}					t_act;

typedef struct		s_size
{
	unsigned short	lin;
	unsigned short	col;
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
t_size				g_size;

void				free_tab(char **tmp);
int					check_big(int n, t_act *act);
void				sig_size(int sig);
void				sig_cont(int sig);
void				sig_tstp(int sig);
void				sig_int(int sig);
int					init(struct termios *saved_term);
int					manage_size(t_act *act, char **tmp, int len, t_size *size);
void				sigtest(void);
int					show_arrow(t_act *act, int argc);
int					*stck_stat(char **tmp, int argc, t_act *act);
int					print(int len, char **tmp, t_act *act);
int					count_space(char *tmp);
int					ft_outc(int c);
t_act				stock_actions(void);
t_size				window_size(void);
int					lenmax_str(t_act *act);
int					show_arrow(t_act *act, int argc);
int					wordbyline(t_size *size, t_act *act);
int					tablen(t_act *act);

#endif
