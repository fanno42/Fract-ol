/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocncopy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:26:18 by jchen             #+#    #+#             */
/*   Updated: 2016/03/16 14:03:50 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_mallocncopy(const char *str, size_t size)
{
	char			*tmp;
	size_t			i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * (size + 1));
	if (tmp == NULL)
		return (NULL);
	else
		while (i < size && *str)
		{
			tmp[i] = str[i];
			i++;
		}
	tmp[i] = '\0';
	return (tmp);
}
