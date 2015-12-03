/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:33:27 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/30 20:58:29 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	nb_str(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			s++;
			res++;
			while (*s != c && *s)
				s++;
		}
	}
	return (res);
}

static char		*add_word(size_t size, char const *s)
{
	char	*res;

	res = ft_strnew(size);
	res = ft_strncpy(res, s, size - 1);
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	char	**res;
	size_t	index;

	if (!(res = (char **)malloc(sizeof(char *) * (nb_str(s, c) + 1))))
		return (NULL);
	res[0] = NULL;
	if (nb_str(s, c) == 0)
		return (res);
	index = 0;
	while (index <= nb_str(s, c))
	{
		while (*s == c)
			s++;
		count = 0;
		if (*s != c)
		{
			count = ft_strlen_ch(s, c);
			res[index] = add_word(count + 1, s);
			s += count;
		}
		index++;
	}
	res[index] = 0;
	return (res);
}
