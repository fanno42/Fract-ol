/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:53:45 by fanno             #+#    #+#             */
/*   Updated: 2016/10/18 15:25:18 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	swag(int x, int y, t_env *e, int i)
{
	double c_r;
	double c_i;
	double z_r;
	double z_i;
	double tmp;

	i = 0;
	z_r = e->param_r;
	z_i = e->param_i;
	c_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	c_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = (z_i - z_i) * tmp + c_i;
		i++;
	}
	pixel_put(e, x, y, choose_color(i, e));
}

void	fanno(int x, int y, t_env *e, int i)
{
	double z_r;
	double z_i;
	double tmp;
	double tmp2;

	i = 0;
	z_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	z_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		tmp2 = z_i;
		z_r = sin(z_r * z_r - z_i * z_i + e->param_r);
		z_i = (tmp + tmp) * tmp2 + e->param_i;
		i++;
	}
	pixel_put(e, x, y, choose_color(i, e));
}

void	hello(int x, int y, t_env *e, int i)
{
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;

	i = 0;
	z_r = e->param_r;
	z_i = e->param_i;
	c_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	c_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = (z_i + z_i) * tmp / 2 + c_i;
		i++;
	}
	pixel_put(e, x, y, choose_color(i, e));
}

void	yolo(int x, int y, t_env *e, int i)
{
	double	z_r;
	double	z_i;
	double	tmp;
	double	tmp2;

	i = 0;
	z_r = (x - WIN_X / 2) / e->zoom + e->place_x;
	z_i = (y - WIN_Y / 2) / e->zoom + e->place_y;
	while (z_r * z_r + z_i * z_i < 4 && i < e->depth)
	{
		tmp = z_r;
		tmp2 = z_i;
		z_r = (z_r * z_r - z_i - z_i * z_i + e->param_r);
		z_i = 2 * (tmp + tmp) * tmp2 + e->param_i;
		i++;
	}
	pixel_put(e, x, y, choose_color(i, e));
}
