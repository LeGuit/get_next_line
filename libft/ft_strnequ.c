/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:30:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/25 13:10:16 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if ((*s1 == '\0' && *s2 == '\0') || (n == 0))
		return (1);
	if (*s1 != *s2)
		return (0);
	else
		return (ft_strnequ(s1 + 1, s2 + 1, n - 1));
}
