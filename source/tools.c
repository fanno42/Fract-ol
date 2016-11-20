/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 11:08:22 by fanno             #+#    #+#             */
/*   Updated: 2016/09/29 11:10:25 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse(int x, int y, void *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
		change_input(e, x, y, 0);
	return (0);
}

int		pressed_button(int button, int x, int y, void *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
		change_input(e, x, y, button);
	return (0);
}

void	change_palette(t_env *e)
{
	if (e->palette < 3)
		e->palette++;
	else
		e->palette = 0;
}
