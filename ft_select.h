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
	char	*kustr;
	char	*kdstr;
	char	*klstr;
	char	*krstr;
	char	*home;
}					t_act;

typedef struct		s_size
{
	unsigned short	lin;
	unsigned short	col;
}					t_size;

#endif
