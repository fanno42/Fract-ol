/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:18:24 by fanno             #+#    #+#             */
/*   Updated: 2016/09/29 13:07:21 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	choose_palette(t_env *e)
{
	if (e->palette == 1)
	{
		(e->palette == 1) ? e->color_in = 0x0000ff : 0;
		(e->palette == 1) ? e->color_start = 0x000000 : 0;
		(e->palette == 1) ? e->color_out = 0x000004 : 0;
	}
	else if (e->palette == 2)
	{
		(e->palette == 2) ? e->color_in = 0x00ff00 : 0;
		(e->palette == 2) ? e->color_start = 0x000000 : 0;
		(e->palette == 2) ? e->color_out = 0x000400 : 0;
	}
	else
	{
		e->color_in = (e->palette == 3) ? 0xff0000 : 0xffffff;
		e->color_start = (e->palette == 3) ? 0x000000 : 0x000000;
		e->color_out = (e->palette == 3) ? 0x040000 : 0x040404;
	}
}

int		refresh(void *e)
{
	draw_window(e);
	draw_window2(e);
	return (0);
}

void	draw_window(t_env *e)
{
	int		y;
	void	(*f)(int x, int y, t_env *e, int i);

	y = -1;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endi));
	if (ft_strcmp(e->fractal, "mandelbrot") == 0)
		(f) = &mandelbrot;
	else if (ft_strcmp(e->fractal, "julia") == 0)
		(f) = &julia;
	else if (ft_strcmp(e->fractal, "fisheye") == 0)
		(f) = &fisheye;
	else if (ft_strcmp(e->fractal, "burningship") == 0)
		(f) = &burningship;
}

void	draw_window2(t_env *e)
{
	int		x;
	int		y;
	void	(*f)(int x, int y, t_env *e, int i);

	y = -1;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->endi));
	if (ft_strcmp(e->fractal, "yolo") == 0)
		(f) = &yolo;
	else if (ft_strcmp(e->fractal, "fanno") == 0)
		(f) = &fanno;
	else if (ft_strcmp(e->fractal, "swag") == 0)
		(f) = &swag;
	else if (ft_strcmp(e->fractal, "hello") == 0)
		(f) = &hello;
	choose_palette(e);
	while (++y < WIN_Y && f)
	{
		x = -1;
		while (++x < WIN_X)
			f(x, y, e, 0);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 0, 2, 0x808080, "fracral\t\t: ");
	mlx_string_put(e->mlx, e->win, 110, 2, 0x808080, e->fractal);
}

void	pixel_put(t_env *e, int x, int y, int color)
{
	unsigned int	new_color;

	new_color = mlx_get_color_value(e->mlx, color);
	e->data[y * e->sl + x * e->bpp / 8] = (new_color & 0xff);
	e->data[y * e->sl + x * e->bpp / 8 + 1] = (new_color & 0xff00) >> 8;
	e->data[y * e->sl + x * e->bpp / 8 + 2] = (new_color & 0xff0000) >> 16;
}
