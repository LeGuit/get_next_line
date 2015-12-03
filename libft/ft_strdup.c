/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:47:12 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 15:31:02 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	else
	{
		while (s1[i])
		{
			dst[i] = s1[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
