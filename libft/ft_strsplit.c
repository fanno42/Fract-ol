/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:00:40 by fanno             #+#    #+#             */
/*   Updated: 2015/12/16 09:44:54 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_str(char const *s, char c)
{
	int				count;
	int				i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	*ft_malloctab(char const *s, char **tab, char c)
{
	int		i1;
	int		i2;
	int		j;

	i1 = 0;
	i2 = 0;
	while (s[i2])
	{
		j = 0;
		while (s[i2] == c && s[i2] != '\0')
			i2++;
		while (s[i2] != c && s[i2] != '\0')
		{
			j++;
			i2++;
		}
		if (j != 0)
			*tab++ = (char *)malloc((j + 1) * sizeof(char));
		if (!(tab - 1))
			return (NULL);
	}
	return (*tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i1;
	int		i2;
	int		i3;
	int		j;

	i1 = 0;
	i3 = 0;
	j = ft_count_str(s, c);
	tab = (char **)malloc((j + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	ft_malloctab(s, tab, c);
	while (i1 != j)
	{
		i2 = 0;
		while (s[i3] == c && s[i3] != '\0')
			i3++;
		while (s[i3] != c && s[i3] != '\0')
			tab[i1][i2++] = s[i3++];
		tab[i1][i2] = '\0';
		i1++;
	}
	tab[i1] = NULL;
	return (tab);
}
