/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:48:00 by gwoodwar          #+#    #+#             */
/*   Updated: 2016/01/21 15:12:24 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE			10000
# define CONTENT(x)			((t_out*)(x)->content)

# include "libft/includes/libft.h"

int					get_next_line(int const fd, char **line);

typedef struct		s_out
{
	int				fdout;
	char			*bufout;
}					t_out;

#endif
