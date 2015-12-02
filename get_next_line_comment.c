/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:58:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/02 13:52:16 by gwoodwar         ###   ########.fr       */
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
	//creation du content du node
	contentnew.fdout = fd;
	// test with real
	contentnew.bufout = ft_strnew(BUFF_SIZE);
	// test with \n in struct 
	// contentnew.bufout = ft_strdup("yo\nlo");
	// test without \n in struct 
	// contentnew.bufout = ft_strdup("yolo");
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
	if (*(out->bufout))
	{
	ft_putendl("cursor before seek \\n : ");
	ft_putendl(out->cursor);
		if ((out->cursor = ft_strchr(out->bufout, '\n')))
		{
	ft_putendl("cursor on \\n : ");
	ft_putendl(out->cursor);
			*(out->cursor) = 0;
			if (!(*line = ft_strdup(out->bufout)))
				return (-1);
	ft_putstr("Aff line rd_lst \\n : ");
	ft_putendl(*line);
			out->bufout = ft_strcpy(out->bufout, (out->cursor) + 1);
	ft_putendl("bufout after rdlist : ");
	ft_putendl(out->bufout);
			out->cursor = out->bufout;
	ft_putendl("cursor after rdlist : ");
	ft_putendl(out->cursor);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(out->bufout)))
				return (-1);
	ft_putstr("Aff line rd_lst no \\n : ");
	ft_putendl(*line);
			*(out->bufout) = 0;
		}
	}
	return (0);
}

static int		rd_fd(int const fd, char **line, t_out *out)
{
	int		ret;
	char	buf[BUFF_SIZE];
	char	*str;
	char	*tmp;

	ft_putendl("Output rd_fd");
	if (!(str = ft_strdup("\0")))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(str = ft_strjoin(str, buf)))
			return (-1);
	ft_putchar('\n');
	ft_putstr("Buffer : ");
	ft_putendl(buf);
	ft_putstr("str join with buf : ");
	ft_putendl(str);
		tmp = str;
		if ((tmp = ft_strchr(tmp, '\n')))
		{
			if (!(out->bufout = ft_strjoin(out->bufout, tmp + 1)))
				return (-1);
	ft_putendl("bufout if \\n : ");
	ft_putendl(out->bufout);
			out->cursor = out->bufout;
	ft_putendl("cursor if \\n : ");
	ft_putendl(out->cursor);
			*tmp = '\0';
	ft_putendl("str if \\n : ");
	ft_putendl(str);
			if (!(*line = ft_strjoin(*line, str)))
				return (-1);
	ft_putstr("str if \\n : ");
	ft_putendl(str);
	ft_putstr("line if \\n : ");
	ft_putendl(*line);
		return (1);
		}
	}
	if (!(*line = ft_strjoin(*line, str)))
		return (-1);
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
	ft_putendl("Output fd_lst");
	ft_putnbr(out->fdout);
	ft_putchar('\n');
	ft_putendl("Bufout : ");
	ft_putendl(out->bufout);
	ft_putendl("Cursor : ");
	ft_putendl(out->cursor);
	ft_putendl("Output rd_lst");
	if ((i = rd_lst(out, line)) == -1)
		return (-1);
	else if (i == 1)
		return (1);
	if ((i = rd_fd(fd, line, out)))
		return (1);
	else if (i == 0)
		return (0);
	/*	else if (i == -1)
		return (-1);
		return (-1);*/
	return (0);
}
