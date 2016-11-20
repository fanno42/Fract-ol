/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:05:02 by fanno             #+#    #+#             */
/*   Updated: 2015/11/25 09:08:42 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	end_src;

	i = 0;
	while (dst[i] && i < n)
		i++;
	end_src = i;
	while (src[i - end_src] && i < n - 1)
	{
		dst[i] = src[i - end_src];
		i++;
	}
	if (end_src < n)
		dst[i] = '\0';
	return (end_src + ft_strlen(src));
}
