/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:16:08 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 20:35:07 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tsrc;
	unsigned char	*tdst;

	tsrc = (unsigned char *)src;
	tdst = (unsigned char *)dst;
	while (n > 0)
	{
		if (*tsrc == (unsigned char)c)
			return (dst + 1);
		*tdst = *tsrc;
		tsrc++;
		tdst++;
		dst++;
		n--;
	}
	return (NULL);
}
