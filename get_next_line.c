/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:01:52 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/27 15:39:15 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_list	**lout;

static char		*ft_read(int const fd)
{
	int		ret;
	char	*str;
	char	*tmp;
	char	buf[BUFF_SIZE];

	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0) //For EOF
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strnew(ft_strlen(str) + ft_strlen(buf));
		ft_strcpy(str, tmp);
		ft_strcat(str, buf);
		free(tmp);
		if (seek_endl(str) == 1)
		{
			str = cut_str(fd, str);
			break ;
		}
	}
	if (ret == (-1))
		return ("ERROR");
	if (ret == (0))
		return ("EOF");
	return (str);
}

static int		seek_endl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
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
			s = ft_strnew(ft_strlen_ch(s, '\n'));
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

int				get_next_line(int const fd, char **line)
{

	if (ft_strcmp(str, "ERROR") == 0)
		return (-1);
	else if (ft_strcmp(str, "EOF") == 0)
		return (0);
	return (1);
}
