/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 12:07:38 by fanno             #+#    #+#             */
/*   Updated: 2016/09/29 11:09:39 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	help_display(void)
{
	ft_putendl("\e[31m-------------------------------------------------------");
	ft_putstr("\n\t\t\e[0mAvailabe fractals :\n\n");
	ft_putstr("\e[32m-\e[0m mandelbrot\n");
	ft_putstr("\e[32m-\e[0m julia\n");
	ft_putstr("\e[32m-\e[0m yolo\n");
	ft_putstr("\e[32m-\e[0m fanno\n");
	ft_putstr("\e[32m-\e[0m swag\n");
	ft_putstr("\e[32m-\e[0m hello\n");
	ft_putstr("\e[32m-\e[0m fisheye \n");
	ft_putstr("\e[32m-\e[0m burningship\n\n\n\n");
	ft_putstr("\t\tAvailabe inputs :\n\n");
	ft_putstr("\e[32m-\e[0m Change color with 'c' (");
	ft_putstr("\e[31mred\e[0m/\e[32mgreen\e[0m/\e[34mblue\e[0m/white)\n");
	ft_putstr("\e[32m-\e[0m Enable/Disable julia sets with 'p'\n");
	ft_putstr("\e[32m-\e[0m Mouse scroll up/down : zoom in/out\n");
	ft_putstr("\e[32m-\e[0m Move mouse to change julia sets\n");
	ft_putstr("\e[32m-\e[0m + or Left / - or Right clic : More/less depth\n");
	ft_putstr("\e[32m-\e[0m Enter : Switch between different fractals\n\n");
	ft_putendl("\e[31m-------------------------------------------------------");
}
