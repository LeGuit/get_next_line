/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:02:39 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/26 12:13:47 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;

	if (!(res = (unsigned char *)malloc(size)))
		return (NULL);
	else
	{
		while (size != 0)
		{
			res[size] = 0;
			size--;
		}
		return (res);
	}
}
