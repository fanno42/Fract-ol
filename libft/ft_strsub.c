/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:24:54 by fanno             #+#    #+#             */
/*   Updated: 2015/11/28 09:56:30 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	dest = ft_memalloc(1);
	if (s && len > 0)
	{
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (dest)
		{
			i = 0;
			while (len--)
				dest[i++] = s[start++];
			dest[i] = '\0';
		}
	}
	return (dest);
}
