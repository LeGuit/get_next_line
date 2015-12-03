/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:51:12 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/27 15:14:07 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstfind(t_list *blist, void *ref, int (*cmp)())
{
	if (!blist)
		return (NULL);
	while (blist)
	{
		if (cmp(blist->content, ref) == 0)
			return (blist);
		blist = blist->next;
	}
	return (NULL);
}
