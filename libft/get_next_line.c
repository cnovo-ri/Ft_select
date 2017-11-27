/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 13:33:38 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/09/14 20:05:14 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					get_next_line(int const fd, char **line)
{
	static t_struct	g;

	if (fd < 0 || fd > 5000 || !line)
		return (-1);
	g.s[fd] = (!g.s[fd]) ? ft_strnew(BUFF_SIZE) : g.s[fd];
	g.t = ft_strncpy(ft_memalloc(BUFF_SIZE), g.s[fd], BUFF_SIZE);
	while (!(ft_strchr(g.t, '\n')))
	{
		if ((g.r = read(fd, g.buf, BUFF_SIZE)) < 1)
		{
			*line = (ft_strlen(g.t) > 0) ? g.t : *line;
			g.s[fd] = (ft_strlen(g.t) > 0) ? NULL : g.s[fd];
			if (g.r < 0)
				return (-1);
			return (ft_strlen(g.t) > 0) ? 1 : 0;
		}
		g.buf[g.r] = '\0';
		g.t_b = ft_strjoin(g.t, g.buf);
		free(g.t);
		g.t = g.t_b;
	}
	*line = ft_strsub(g.t, 0, ft_strlen(g.t) - ft_strlen(ft_strchr(g.t, '\n')));
	if (ft_strchr(g.t, '\n'))
		g.s[fd] = ft_strncpy(g.s[fd], ft_strchr(g.t, '\n') + 1, BUFF_SIZE);
	return (1);
}
