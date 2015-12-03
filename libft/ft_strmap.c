/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:24:00 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/25 13:07:07 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	res = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}
