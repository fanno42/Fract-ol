/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:52:36 by fanno             #+#    #+#             */
/*   Updated: 2015/12/18 09:46:18 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content = ft_memalloc(content_size);
		if (!lst->content)
		{
			free(lst);
			return (NULL);
		}
		ft_memmove((lst->content), content, content_size);
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
