/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanno <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:00:59 by fanno             #+#    #+#             */
/*   Updated: 2016/05/26 18:05:08 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct	s_fd
{
	int			id;
	int			i;
	int			j;
	int			rret;
	char		*buffer;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(int const fd, char **line);

#endif
