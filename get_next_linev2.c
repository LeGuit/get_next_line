/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:59:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/30 17:58:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char		*ft_read(int const fd, char *str, t_list **lout)
{
	int		ret;
	char	buf[BUFF_SIZE];
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(str = ft_strealloc(str, ft_strlen(str) + ft_strlen(buf))))
			return (NULL);
		str = ft_strcat(tmp, buf);
		tmp = str;
		if (ft_strchr(tmp, '\n'))
		{
			lout = getlstout(lout, fd, tmp + 1); // /!\ tmp is on \n +1
			str = ft_strsub(str, 0, (size_t)(tmp - str));
			free (tmp);
			return (str);
		}
	}
	if (ret == (-1))
		str = NULL;
	else if (ret == 0)
		*str = '\0';
	return (str);
}

t_list			**getlstout(t_list **lout )

static char		*is_in_lst(int const fd, t_list **lout)
{
	char	*tmp;
	char	*str;

	while (*lout->next)
	{
		if (CAST(lout)->fdout == fd)
		{
			if (tmp = ft_strchr(CAST(lout)->sout, '\n'))
			{
				str = ft_strsub(CAST(lout)->sout, 0, (size_t)(tmp + 1 - str)); // with \n
				CAST(lout)->sout = tmp + 1;
			}
			else
			{
				str = ft_strdup(CAST(lout)->sout);
				CAST(lout)->sout += (ft_strlen(CAST(lout)->sout));
			}
			return (str);
		}
		*lout = *lout->next;
	}
	return (NULL);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	**lout;
	char			*tmp;

	while (*line)
		*line++;
	tmp = is_in_lst(fd, lout);
	if (ft_strchr(tmp, '\n')) //maybe test fct outside
	{
		*line = ft_strsub(tmp, 0, ft_strlen(tmp) - 1);
		free(tmp);
		return (1);
	}
	if ((!(line = ft_read(fd, tmp, lout))))
		return (-1);
	if (*line == '\0')
		return (0);
	return (1);
}







