/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:48:00 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/27 14:27:37 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE			32
# define CAST(t)			((t_dout*)out->content)
// # define MIN_LEN(x, y)	((x) < (y) ? (x) : (y))

int					get_next_line(int const fd, char **line);

typedef struct		s_dout
{
	int const		fdout;
	char			*sout;
}					t_dout;


int fd = ((t_data*)list->content)->fdout;

#endif
