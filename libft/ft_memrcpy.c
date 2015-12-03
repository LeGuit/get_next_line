/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:14:03 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/26 13:19:13 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tsrc;
	unsigned char	*tdst;

	tsrc = (unsigned char *)src;
	tdst = (unsigned char *)dst;
	while (n > 0)
	{
		*(tdst + n - 1) = *(tsrc + n - 1);
		n--;
	}
	return (dst);
}
