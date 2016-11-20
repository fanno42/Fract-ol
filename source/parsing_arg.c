/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 12:31:38 by fanno             #+#    #+#             */
/*   Updated: 2016/10/06 14:07:25 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		parsing_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("\nUsage: ./fractol <\e[32mfractal_name");
		ft_putstr(" \e[0m \e[31mhelp\e[0m>\n\n");
		return (0);
	}
	else if (ft_strcmp(argv[1], "help") == 0)
	{
		help_display();
		return (0);
	}
	else if (ft_strcmp("julia", argv[1]) && ft_strcmp("swag", argv[1]) &&
			ft_strcmp("fisheye", argv[1]) && ft_strcmp("fanno", argv[1]) &&
			ft_strcmp("burningship", argv[1]) && ft_strcmp("hello", argv[1]) &&
			ft_strcmp("yolo", argv[1]) && ft_strcmp("mandelbrot", argv[1]))
	{
		ft_putendl("\n\n\e[31m/1\\\e[0m	Invalid fractal	\e[31m/!\\\e[0m\n");
		return (0);
	}
	return (1);
}
