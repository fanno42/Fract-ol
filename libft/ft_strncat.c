/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 10:24:21 by fanno             #+#    #+#             */
/*   Updated: 2015/11/27 17:36:09 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*str;

	str = dest;
	while (*str != '\0')
	{
		str++;
	}
	while (*src != '\0' && n > 0)
	{
		*str = *src;
		str++;
		src++;
		n--;
	}
	*str = '\0';
	return (dest);
}
