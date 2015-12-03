/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:25:10 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/25 13:07:29 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	res = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
