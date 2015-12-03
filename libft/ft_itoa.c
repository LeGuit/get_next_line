/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:59:56 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/12/01 18:09:30 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	size_str(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*res;

	i = size_str(n);
	res = ft_strnew(i);
	if (n == 0)
		return ("0");
	if (n < 0)
		res[0] = '-';
	while (n != 0)
	{
		res[i - 1] = ABS(n % 10) + '0';
		i--;
		n /= 10;
	}
	return (res);
}
