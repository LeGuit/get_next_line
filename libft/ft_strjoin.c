/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:31:03 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/02 11:54:28 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;

	if (!s1 || !s2)
		return (ft_strdup(((s1) ? s1 : s2)));
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		res[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	res[i] = '\0';
	return (res);
}
