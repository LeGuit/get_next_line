/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:58:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/02 20:18:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static t_out	*fd_lst(int const fd, t_list **headptr)
{
	t_list	*it;
	t_list	*node;
	t_out	contentnew;

	it = *headptr;
	while (it)
	{
		if (CONTENT(it)->fdout == fd)
			return (CONTENT(it));
		it = it->next;
	}
	contentnew.fdout = fd;
	contentnew.bufout = ft_strnew(BUFF_SIZE);
	contentnew.cursor = contentnew.bufout;
	if (!(node = ft_lstnew(&contentnew, sizeof(t_out))))
	{
		free(contentnew.bufout);
		return (NULL);
	}
	ft_lstadd(headptr, node);
	return (CONTENT(node));
}

static int		rd_lst(t_out *out, char **line)
{
	char	*tmp;

	if (!*(out->bufout))
		return (0);
	if ((out->cursor = ft_strchr(out->bufout, '\n')))
	{
		*(out->cursor) = 0;
		if (!(*line = ft_strjoin(*line, out->bufout)))
			return (-1);
		out->bufout = ft_strcpy(out->bufout, (out->cursor) + 1);
		out->cursor = out->bufout;
		return (1);
	}
	tmp = *line;
	if (!(*line = ft_strjoin(*line, out->bufout)))
		return (-1);
	free(tmp);
	*(out->bufout) = 0;
	return (0);
}

static int		rd_fd(int const fd, char **line, t_out *out)
{
	int		ret;

	while ((ret = read(fd, out->bufout, BUFF_SIZE)) > 0)
	{
		(out->bufout)[ret] = 0;
		if (rd_lst(out, line) == 1)
			return (1);
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*head = NULL;
	t_out			*out;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	*line = 0;
	if (!(out = fd_lst(fd, &head)))
		return (-1);
	if ((ret = rd_lst(out, line)))
		return (ret);
	ret = rd_fd(fd, line, out);
	return (ret);
}
