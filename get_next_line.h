/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:48:00 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/02 20:09:34 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE			2
# define CONTENT(x)			((t_out*)(x)->content)

int					get_next_line(int const fd, char **line);

typedef struct		s_out
{
	int				fdout;
	char			*bufout;
	char			*cursor;
}					t_out;

#endif
