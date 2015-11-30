/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:58:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/30 21:15:46 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static t_list	*fd_lst(int const fd, t_list **lout)
{
	t_list	*nout;
	t_out	*tmp;

	while ((*lout)->next)
	{
		if (CAST(*lout)->fdout == (int)fd)
			return (*lout);
		*lout = (*lout)->next;
	}
	if (!(nout = ft_lstnew(tmp, sizeof(t_out))))
		return (NULL);
	CAST(nout).fdout = fd;
	CAST(nout)->bufout = NULL;
	CAST(nout)->cursor = CAST(nout)->bufout;
	ft_lstadd(lout, nout);
	return (*lout);
}

static int		rd_lst(t_out *lout, char **line)
{
	if ((lout->cursor = ft_strchr(lout->bufout, '\n')))
	{
		*(lout->cursor) = 0;
		if(!(*line = ft_strdup(lout->bufout)))
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

int			get_next_line(int const fd, char **line)
{
	static t_list	**lout = NULL;
	int				i;

	if(!(*lout = fd_lst(fd, lout)))
		return (-1);
	if ((i = rd_lst(CAST(*lout), line)) == -1)
		return (-1);
	else if (i == 1)
		return (1);
	if ((i = rd_fd(fd, line, CAST(*lout))))
		return (0);
	else if (i == 1)
		return (1);
	else if (i == -1)
		return (-1);
}
