/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:26:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/24 14:23:41 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || (*s1 == '\0' && *s2 == '\0'))
		return (0);
	if (*s1 != *s2)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
