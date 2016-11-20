/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:21:31 by fanno             #+#    #+#             */
/*   Updated: 2015/11/25 10:39:09 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;
	size_t			i;

	s1 = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (i != n)
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
