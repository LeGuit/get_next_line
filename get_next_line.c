/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:58:58 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/30 19:32:03 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	is_in_lst(int const fd, t_dout *out, char **line)
{
	char *cursor;
	while (*lout->next)
	{
		if (CAST(lout)->fdout == fd)
		{
			if (cursor = ft_strchr(CAST(lout)->bufout, '\n'))
			{
				*cursor = 0;
				if cursor = BUFFSIZE
				*(CAST(lout)->cursor) = '\0';
				(CAST(lout)->cursor)++;
				(CAST(lout)->bufout = ft_strcpy(CAST(lout)->bufout,
												CAST(lout)->cursor));
				*line = ft_strdup(CAST(lout)->bufout);
				return (1);
			}
			else
			{
				*line = ft_strdup(CAST(lout)->bufout);
				CAST(lout)->cursor += (ft_strlen(CAST(lout)->bufout));
				return (0);
			}
		}
		*lout = *lout->next;
	}
	return (-1);
}

static int		rd_lst(t_out *lout, char **line)
{
	char	*cursor;

	if (cursor = ft_strchr(lout->bufout, '\n'))
	{

	}
	else
	{
		if (!(*line = ft_strdup(lout->bufout)))
			return (-1);
		*(lout->bufout) = 0;
		return (0);
	}
}

static t_list	*fd_lst(int const fd, t_list **lout)
{
	t_list	*nout;
	t_out	*tmp;

	while (*lout->next)
	{
		if (CAST(*lout).fdout == fd)
			return (*lout);
		*out = *lout->next;
	}
	if (!(nout = ft_lstnew(tmp, sizeof(t_out))))
		return (NULL);
	CAST(nout).fdout = fd;
	CAST(nout)->bufout = NULL;
	CAST(nout)->cursor = CAST(nout)->bufout;
	ft_lstadd(lout, nout);
	return (lout);
}

int			get_next_line(int const fd, char **line)
{
	static t_list	**lout = NULL;
	int				i;

	if(!(*lout = fd_lst(fd, lout)))
		return (-1);
	if (i = rd_lst(CAST(*lout), line);

	
}
