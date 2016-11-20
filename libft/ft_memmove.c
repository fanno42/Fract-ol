/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:37:33 by fanno             #+#    #+#             */
/*   Updated: 2015/12/16 10:03:27 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const unsigned char		*s1;
	unsigned char			*s2;
	size_t					i;

	s1 = src;
	s2 = dst;
	if (s2 > s1)
	{
		i = n;
		while (i-- > 0)
			s2[i] = s1[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	return (dst);
}
