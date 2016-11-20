/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:27:29 by fanno             #+#    #+#             */
/*   Updated: 2016/10/23 09:30:24 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../include/keys.h"
# include "../include/libft.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# define WIN_X 800
# define WIN_Y 600

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	char		*fractal;
	int			bpp;
	int			sl;
	int			endi;
	int			win_x;
	int			win_y;
	double		depth;
	double		zoom;
	int			x;
	int			y;
	double		place_x;
	double		place_y;
	double		param_r;
	double		param_i;
	int			param;
	int			palette;
	int			color_in;
	int			color_out;
	int			color_start;
}				t_env;

/*
** display
*/

void			choose_fractal(t_env *e);
void			do_input(t_env *e, int key);
void			change_input(t_env *e, int x, int y, int fct);
int				find_key(int key, void *e);
int				expose_find_key(int key, void *e);

/*
** fractal
*/

int				choose_color(double i, t_env *e);
void			mandelbrot(int x, int y, t_env *e, int i);
void			julia(int x, int y, t_env *e, int i);
void			fisheye(int x, int y, t_env *e, int i);
void			burningship(int x, int y, t_env *e, int i);

/*
** fractal2
*/

void			swag(int x, int y, t_env *e, int i);
void			fanno(int x, int y, t_env *e, int t);
void			hello(int x, int y, t_env *e, int i);
void			yolo(int x, int y, t_env *e, int i);

/*
** help
*/

void			help_display(void);

/*
** input
*/

void			choose_palette(t_env *e);
int				refresh(void *e);
void			draw_window(t_env *e);
void			draw_window2(t_env *e);
void			pixel_put(t_env *e, int x, int y, int color);

/*
** parsing_arg
*/

int				parsing_arg(int argc, char **argv);

/*
** tools
*/

int				mouse(int x, int y, void *e);
int				pressed_button(int button, int x, int y, void *e);
void			change_palette(t_env *e);

/*
** main
*/

void			new_env(t_env *e);
int				main(int argc, char **argv);

#endif
