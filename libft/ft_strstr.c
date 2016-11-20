/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:17:16 by fanno             #+#    #+#             */
/*   Updated: 2015/11/27 18:30:24 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i1;
	int	i2;
	int	i_tf;

	i1 = 0;
	i_tf = 0;
	if (to_find[0] == '\0')
		return (char *)(str);
	while (str[i1] != '\0')
	{
		i2 = i1;
		i_tf = 0;
		while (str[i2] == to_find[i_tf])
		{
			i2++;
			i_tf++;
			if (to_find[i_tf] == '\0')
				return (char *)(&str[i1]);
		}
		i1++;
	}
	return (NULL);
}
