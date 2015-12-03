/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:58:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/03 10:55:27 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_out	*seek_fd(int const fd, t_list **headptr)
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
	if (!(node = ft_lstnew(&contentnew, sizeof(t_out))))
	{
		free(contentnew.bufout);
		return (NULL);
	}
	ft_lstadd(headptr, node);
	return (CONTENT(node));
}

static int		fetch_in_buffer(t_out *out, char **line)
{
	char	*tmp;
	char	*cursor;

	if (!*(out->bufout))
		return (0);
	if (!(cursor = ft_strchr(out->bufout, '\n')))
		cursor = out->bufout + BUFF_SIZE;
	*cursor = 0;
	tmp = *line;
	if (!(*line = ft_strjoin(tmp, out->bufout)))
		return (-1);
	free(tmp);
	ft_strcpy(out->bufout, cursor + 1);
	if (out->bufout + BUFF_SIZE == cursor)
		return (0);
	return (1);
}

static int		read_in_fd(int const fd, char **line, t_out *out)
{
	int		ret;

	while ((ret = read(fd, out->bufout, BUFF_SIZE)) > 0)
	{
		(out->bufout)[ret] = 0;
		ret = fetch_in_buffer(out, line);
		if (ret)
			return (ret);
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
	if (!(out = seek_fd(fd, &head)))
		return (-1);
	if ((ret = fetch_in_buffer(out, line)))
		return (ret);
	ret = read_in_fd(fd, line, out);
	return (ret);
}
