/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_ch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:14:42 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/27 11:15:52 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlen_ch(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s != c && *s)
	{
		s++;
		size++;
	}
	return (size);
}
