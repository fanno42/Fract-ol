/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:52:49 by fanno             #+#    #+#             */
/*   Updated: 2015/11/28 10:20:12 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str != '\0')
	{
		i = 0;
		while (i <= size)
			str[i++] = '\0';
	}
	return (str);
}
