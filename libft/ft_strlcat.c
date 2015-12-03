/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:26:15 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 19:52:50 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	nmax;
	size_t	res;
	size_t	i;

	nmax = size - ft_strlen(dst) - 1;
	res = ft_strlen(src);
	i = 0;
	while (dst[i] && i < size)
		i++;
	res += ((i < size) ? i : size);
	if ((int)nmax > 0)
		ft_strncat(dst, src, nmax);
	return (res);
}
