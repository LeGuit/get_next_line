/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:55:01 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/02 23:07:47 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	int		fd[10] = {0};
	int		ret;
	int		i;
	char	*line;
	int		j;
	line = NULL;
	if (ac < 2)
		return (0);
	i = 0;
	while (i < ac)
	{
		fd[i] = open(av[i + 1], O_RDONLY);
		i++;
	}
	i = 0;
	j = 15;
	while (j-- > 0)
	{
		ret = get_next_line(fd[i], &line);
		printf("%d :%d: %d: %s\n",j, fd[i], ret, line);
		i = (i + 1) % (ac - 1);
		free(line);
	}
	ft_putchar('\n');
	return (0);
}
