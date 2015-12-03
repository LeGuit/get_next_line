/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:16:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/25 14:22:59 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		tmp;
	size_t		i;

	i = ft_strlen(s) + 1;
	tmp = (char)c;
	while (*s)
		s++;
	while (*s != tmp && i != 0)
	{
		s--;
		i--;
	}
	if (i == 0)
		return (NULL);
	else
		return (char *)(s);
}
