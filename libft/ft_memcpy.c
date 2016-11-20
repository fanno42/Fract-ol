/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:27:21 by fanno             #+#    #+#             */
/*   Updated: 2015/11/27 16:50:57 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dest;
	if (n == 0 || dest == src)
		return (dest);
	while (--n)
		*s2++ = *s1++;
	*s2 = *s1;
	return (dest);
}
