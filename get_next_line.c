/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:01:52 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/27 14:27:32 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_list	**lout;

static char		*ft_read_size(int const fd, size_t size)
{
	int		ret;
	char	*str;
	char	*tmp;
	char	buf[BUFF_SIZE];

	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > BUFF_SIZE) //For EOF
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strnew(ft_strlen(str) + ft_strlen(buf));
		ft_strcpy(str, tmp);
		ft_strcat(str, buf);
		free(tmp);
	}
	*(str + ft_strlen(str) + ft_strlen(buf) /*- 1*/) = '\0';
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
			s = ft_strnew(ft_strlen_ch(s, '\n'));
			ft_strncpy(s, tmp, i /*- 1*/);
			tmp = ft_strchr(tmp, '\n');
			CAST(out)->sout = ft_strnew(ft_strlen(tmp));
			CAST(out)->sout = ft_strncpy(out->sout, tmp,
				ft_strlen(tmp)/* - 1*/);
			(T_Oout)content->fdout = fd;
			ft_lstadd_last(
		}
		i++;
	}
	return (str);
}

int				get_next_line(int const fd, char **line)
{
}
