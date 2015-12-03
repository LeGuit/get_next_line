/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:32:11 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/26 13:12:01 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	size_blanck_less(char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s))
		return (1);
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		i++;
		j--;
	}
	return (ft_strlen(s) - i + 1);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*res;
	size_t	j;

	j = size_blanck_less(s);
	res = ft_strnew(j);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	i = 0;
	while (i < j - 1)
	{
		res[i] = *s;
		i++;
		s++;
	}
	return (res);
}
