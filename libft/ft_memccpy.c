/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:48:38 by fanno             #+#    #+#             */
/*   Updated: 2015/12/16 09:50:58 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	to_find;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	to_find = (unsigned char)c;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	while (i != n && s1[i] != to_find)
	{
		s2[i] = s1[i];
		i++;
	}
	if (s1[i] == to_find)
	{
		s2[i] = to_find;
		return (&s2[i + 1]);
	}
	return (NULL);
}
