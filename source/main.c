/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:51:50 by fanno             #+#    #+#             */
/*   Updated: 2016/09/29 11:35:10 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	new_env(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fanno_fractol");
	e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->depth = 10;
	e->zoom = WIN_X / 4;
	e->place_x = 0;
	e->place_y = 0;
	e->param = 0;
	e->palette = 0;
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (!parsing_arg(argc, argv))
		return (0);
	new_env(&e);
	e.fractal = argv[1];
	mlx_hook(e.win, 1, (1 << 11), pressed_button, &e);
	mlx_hook(e.win, 2, (1 << 11), pressed_button, &e);
	mlx_hook(e.win, 4, (1 << 11), pressed_button, &e);
	mlx_hook(e.win, 5, (1 << 12), pressed_button, &e);
	mlx_hook(e.win, 6, (1L << 6), mouse, &e);
	mlx_hook(e.win, 2, 0, expose_find_key, &e);
	mlx_key_hook(e.win, find_key, &e);
	mlx_loop_hook(e.mlx, refresh, &e);
	mlx_loop(e.mlx);
	return (0);
}
