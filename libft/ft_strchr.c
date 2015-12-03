/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:15:20 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 20:21:41 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char tmp;

	tmp = (char)c;
	while (*s != tmp)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (char *)(s);
}
