/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:12:18 by cnovo-ri          #+#    #+#             */
/*   Updated: 2018/04/25 09:38:36 by cnovo-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		intro2(void)
{
	ft_putstr_fd("\033[H\033[2J", 0);
	ft_putendl_fd(" _______ _                 _                          _", 0);
	ft_putendl_fd("|__   __| |               | |                        | |", 0);
	ft_putstr_fd("   | |  | |__   __ _ _ __ | | _____   _ __ ___   __ _| ", 0);
	ft_putendl_fd("|_ ___", 0);
	ft_putstr_fd("   | |  | '_ \\ / _` | '_ \\| |/ / __| | '_ ` _ \\ / _` | ", 0);
	ft_putendl_fd("__/ _ \\", 0);
	ft_putstr_fd("   | |  | | | | (_| | | | |   <\\__ \\ | | | | | | ", 0);
	ft_putendl_fd("(_| | ||  __/", 0);
	ft_putstr_fd("   |_|  |_| |_|\\__,_|_| |_|_|\\_\\___/ |_| |_| |_", 0);
	ft_putendl_fd("|\\__,_|\\__\\___|", 0);
	sleep(2);
}
