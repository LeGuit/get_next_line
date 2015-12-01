/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:58:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/01 17:30:51 by gwoodwar         ###   ########.fr       */
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
//	ft_putstr("test fd_lst 1 \n");
	while (it)
	{
//	ft_putstr("test fd_lst boucle \n");
		if (CONTENT(it)->fdout == fd)
			return (CONTENT(it));
		it = it->next;
	}
	//creation du content du node
	contentnew.fdout = fd;
//	contentnew.bufout = ft_strnew(BUFF_SIZE);
	contentnew.bufout = ft_strdup("yolo");
	contentnew.cursor = contentnew.bufout;

	if (!(node = ft_lstnew(&contentnew, sizeof(t_out))))
	{
		free(contentnew.bufout);
		return (NULL);
	}
	ft_lstadd(headptr, node);
	return (CONTENT(node));
}

static int		rd_lst(t_out *lout, char **line)
{
	if ((lout->cursor = ft_strchr(lout->bufout, '\n')))
	{
		*(lout->cursor) = 0;
		if (!(*line = ft_strdup(lout->bufout)))
			return (-1);
		lout->bufout = ft_strcpy(lout->bufout, lout->cursor);
		lout->cursor = lout->bufout;
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(lout->bufout)))
			return (-1);
		*(lout->bufout) = 0;
		return (0);
	}
}

static int		rd_fd(int const fd, char **line, t_out *lout)
{
	int		ret;
	char	buf[BUFF_SIZE];
	char	*str;
	char	*tmp;

	str = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(str = ft_strjoin(str, buf)))
			return (-1);
		tmp = str;
		if (ft_strchr(tmp, '\n'))
		{
			if (!(lout->bufout = ft_strjoin(lout->bufout, tmp)))
				return (-1);
			*tmp = 0;
			if (!(*line = ft_strjoin(*line, str)))
				return (-1);
		}
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*head = NULL;
	t_out			*out;
	int				i;

	ft_putstr("test gnl \n");
	if (!(out = fd_lst(fd, &head)))
		return (-1);
	ft_putnbr(out->fdout);
	ft_putchar('\n');
	ft_putendl(out->bufout);
	ft_putendl(out->cursor);
/*	if ((i = rd_lst(CONTENT(*lout), line)) == -1)
		return (-1);
	else if (i == 1)
		return (1);
	if ((i = rd_fd(fd, line, CONTENT(*lout))))
		return (0);
	else if (i == 1)
		return (1);
	else if (i == -1)
		return (-1);
	return (-1);*/
	return (0);
}
