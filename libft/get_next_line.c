/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:18:37 by fanno             #+#    #+#             */
/*   Updated: 2016/05/26 17:59:44 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static t_fd	*get_node(int const fd, t_fd **fd_list)
{
	t_fd	*tmp;
	t_fd	*newnode;

	tmp = *fd_list;
	while (tmp)
	{
		if (tmp->id == fd)
			return (tmp);
		tmp = tmp->next;
	}
	newnode = (t_fd *)malloc(sizeof(t_fd));
	newnode->id = fd;
	newnode->i = -1;
	newnode->next = NULL;
	newnode->buffer = ft_strnew(BUFF_SIZE);
	tmp = *fd_list;
	if (tmp)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newnode;
	}
	else
		*fd_list = newnode;
	return (newnode);
}

static void	clear_node(t_fd *node, t_fd **fd_list)
{
	t_fd	*tmp;
	t_fd	*prev_node;

	tmp = *fd_list;
	if (node != tmp)
	{
		while (tmp->next != node)
			tmp = tmp->next;
		prev_node = tmp;
		tmp = tmp->next;
		prev_node->next = tmp->next;
	}
	else
		*fd_list = node->next;
	if (node->buffer)
		free(node->buffer);
	free(node);
}

static int	parse_char(t_fd *node, char **line)
{
	char	*tmp;

	if (node->buffer[node->i] == '\n' || node->i == node->rret)
	{
		if (node->i - node->j > 0)
		{
			tmp = ft_strsub(node->buffer, node->j, node->i - node->j);
			ft_strmerge(line, &tmp);
		}
		if (node->buffer[node->i] != '\n')
		{
			if (node->buffer[node->i] == '\0' && **line == '\0')
				return (0);
			if (node->rret < BUFF_SIZE)
				return (1);
			return (3);
		}
		return (1);
	}
	return (2);
}

static int	get_line(t_fd *node, char **line, int result)
{
	while (++node->i < BUFF_SIZE)
	{
		if (!(*node->buffer) || result == 3)
		{
			if ((node->rret = read(node->id, node->buffer, BUFF_SIZE)) == -1)
				return (-1);
			else if (node->rret == 0 && **line == '\0')
				return (0);
			else if (node->rret == 0)
				return (1);
		}
		if ((result = parse_char(node, line)) != 2)
			return (result);
	}
	return (2);
}

int			get_next_line(int const fd, char **line)
{
	static t_fd	*fd_list;
	t_fd		*node;
	int			result;
	char		*tmp;

	if (fd > 256 || fd < 0 || line == NULL || BUFF_SIZE == 0)
		return (-1);
	node = get_node(fd, &fd_list);
	node->j = node->i + 1;
	*line = ft_strnew(sizeof(char));
	result = 2;
	while ((result = get_line(node, line, result)) >= 2)
	{
		tmp = ft_strsub(node->buffer, node->j, node->i - node->j);
		ft_strmerge(line, &tmp);
		node->i = -1;
		node->j = 0;
		ft_memset(node->buffer, '\0', BUFF_SIZE);
	}
	if (result < 1)
		clear_node(node, &fd_list);
	return (result);
}
