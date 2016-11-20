/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:45:22 by fanno             #+#    #+#             */
/*   Updated: 2015/11/30 11:27:29 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	char			*str;

	size = ft_strlen(s);
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	while (size--)
		str[size] = f(size, s[size]);
	return (str);
}
