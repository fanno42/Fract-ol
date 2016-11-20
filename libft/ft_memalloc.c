/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:03:55 by fanno             #+#    #+#             */
/*   Updated: 2015/11/28 10:22:25 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*new;
	size_t			i;

	new = NULL;
	new = (unsigned char *)malloc(size);
	if (new)
	{
		i = 0;
		while (size--)
			new[i++] = 0;
	}
	return ((void *)new);
}
