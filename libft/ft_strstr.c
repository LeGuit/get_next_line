/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:17:51 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/30 17:45:44 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && (s2[j] != '\0'))
		{
			if (s1[i + j] == '\0')
				return (NULL);
			else
				j++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
