/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:55:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/02 12:09:45 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "libft/libft.h"

int		main(int ac, char **av)
{
	int		fd;
	int		resgnl;
	int		i;
	char	*line;

	line = NULL;
	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			{i++; continue ;}
 		resgnl = get_next_line(fd, &line);
		ft_putnbr(resgnl);
		ft_putchar('\n');
		ft_putstr(line);
 		resgnl = get_next_line(fd, &line);
		ft_putnbr(resgnl);
		ft_putchar('\n');
		ft_putstr(line);
 		resgnl = get_next_line(fd, &line);
		ft_putnbr(resgnl);
		ft_putchar('\n');
		ft_putstr(line);
		i++;
	/*	
		while ((resgnl = get_next_line(fd, &line)) >= 0)
		{
			i++;
		}*/
	}
	ft_putchar('\n');
	return (0);
}
