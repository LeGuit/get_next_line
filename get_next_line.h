/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:48:00 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/30 18:46:17 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE			32
# define CAST(x)			((t_dout*)x->content)

int					get_next_line(int const fd, char **line);

typedef struct		s_out
{
	int const		fdout;
	char			*bufout;
	char			*cursor;
}					t_out;



#endif
