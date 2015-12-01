/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:55:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/01 17:10:34 by gwoodwar         ###   ########.fr       */
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
 		get_next_line(fd, &line);
 		get_next_line(fd, &line);
		i++;
	/*	
		while ((resgnl = get_next_line(fd, &line)) >= 0)
		{
			ft_putnbr(resgnl);
			ft_putstr(line[i]);
			i++;
		}*/
	}
	ft_putchar('\n');
	return (0);
}
