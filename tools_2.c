/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:16:36 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/02/18 16:19:31 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				free_tab(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

int					tablen(t_act *act)
{
	int		i;

	i = 0;
	if (!(g_act.s_argv))
		return (0);
	while (g_act.s_argv[i])
		i++;
	return (i);
}

int					count_space(char *tmp)
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

char				**morespaces(t_act *act)
{
	int		i;

	i = 0;
	if (!(act->tmp = (char **)malloc(sizeof(char *) * tablen(act) + 1)))
		return (NULL);
	while (i < tablen(act))
	{
		if (i != 0)
			act->tmp[i] = g_act.s_argv[i];
		i++;
	}
	act->tmp[i] = NULL;
	return (act->tmp);
}

int					wordbyline(t_size *size, t_act *act)
{
	int		sizemax;
	int		wordbyline;

	sizemax = lenmax_str(act);
	wordbyline = size->col / (sizemax + 5);
	return (wordbyline);
}
