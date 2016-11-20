/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:57:28 by fanno             #+#    #+#             */
/*   Updated: 2015/11/28 09:51:51 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*temp_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	temp_str = str;
	while (*s1 != '\0')
		*temp_str++ = *s1++;
	while (*s2 != '\0')
		*temp_str++ = *s2++;
	*temp_str = '\0';
	return (str);
}
