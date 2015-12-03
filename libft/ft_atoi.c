/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:10:26 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/02 22:58:32 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		res;

	while (*str == '\n' || *str == '\v' || *str == '\r' || *str == ' ' ||
			*str == '\f' || *str == '\t')
		str++;
	sign = (*str == '-' ? 1 : 0);
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str) == 1)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = (sign == 1 ? (-res) : res);
	return (res);
}
