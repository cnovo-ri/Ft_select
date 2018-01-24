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
	char	*cmstr;
	char	*clstr;
	char	*invis;
	char	*normal;
	char	*home;
}					t_act;

typedef struct		s_size
{
	unsigned short	lin;
	unsigned short	col;
	unsigned short	lin_tmp;
	unsigned short	col_tmp;
}					t_size;

int					ft_outc(int c);
int					default_shell(void);
t_act				stock_actions(void);
t_size				window_size(void);
int					lenmax_str(char **argv);
int					show_arrow(t_act act, int argc, char **argv);
int					wordbyline(t_size *size, char **argv);

#endif
