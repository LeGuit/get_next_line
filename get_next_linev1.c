/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:01:52 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/30 10:04:03 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_list	**lout;

static char		*ft_read(int const fd, char *str)
{
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE];
	int		i;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		if (!(str = ft_strnew(ft_strlen(str) + ft_strlen(buf))))
			return (NULL);
		ft_strcpy(str, tmp);
		ft_strcat(str, buf);
		free(tmp);
		i = -1;
		while (s[++i])						//seek_endl
		{
			if (s[i] == '\n')
				return (cut_str(fd, str));
		}
	}
	if (ret == (-1))
		return ("ERROR");
	if (ret == (0))
		return (str);
}

static char		*cut_str(int const fd, char *s)
{
	char	*tmp;
	t_list	*out;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			tmp = s;
			if(!(s = ft_strnew(ft_strlen_ch(s, '\n'))))
				return (NULL);
			ft_strncpy(s, tmp, i /*- 1*/);
			tmp = ft_strchr(tmp, '\n');
			CAST(out)->sout = ft_strnew(ft_strlen(tmp));
			CAST(out)->sout = ft_strncpy(out->sout, tmp,
					ft_strlen(tmp)/* - 1*/);
			CAST(out)content->fdout = fd;
			ft_lstadd_last(lout, out);
		}
		i++;
	}
	return (str);
}

static int		egalegal(int fdout, int fd)
{
	if (fdout == fd)
		return (0);
	return (1);
}

static char		*str_link(int const fd, t_list **lout, char *str)
{
	t_list	*matchlst;
	int		i;

	if (!(matchlist = ft_lstfind(*lout, fd, egalegal)))
		return (NULL);
	i = 0;
	while ((CAST(matchlist)->sout)[i] != '\n')
		i++;
	if (!(str = ft_strnew(ft_strlen(i))))
		return (NULL);
	str = strncpy(str, CAST(matchlist)->sout, i);
	CAST(matchlist)->sout += i;
	return (str);
}

int				get_next_line(int const fd, char **line)
{
	char	*str;

	str = str_link(fd, lout, str);
	str = ft_read(fd, str);

	if (ft_strcmp(str, "ERROR") == 0)
		return (-1);
//	else if (ft_strcmp(str, "EOF") == 0)
//		return (0);
	while (**line)
		*line++;
	*line = str;
	return (1);
}
