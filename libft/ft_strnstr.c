/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:26:33 by fanno             #+#    #+#             */
/*   Updated: 2015/11/27 18:43:04 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	int			k;

	i = 0;
	k = 0;
	if (s2[0] == '\0')
		return (char *)(s1);
	while (i < n && s1[i])
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k] && j < n)
		{
			j++;
			k++;
			if (s2[k] == '\0')
				return (char *)(&s1[i]);
		}
		i++;
	}
	return (NULL);
}
