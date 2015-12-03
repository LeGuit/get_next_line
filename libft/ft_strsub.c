/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:30:45 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/25 12:50:25 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	res = ft_strnew(len);
	i = 0;
	while (i < (int)len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}
