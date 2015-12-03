

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:24:57 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/26 15:56:23 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res_list;

	if (!(res_list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	res_list->next = NULL;
	if (content == NULL)
	{
		res_list->content = NULL;
		res_list->content_size = 0;
	}
	else
	{
		if (!(res_list->content = malloc(content_size)))
			return (NULL);
		ft_memmove(res_list->content, content, content_size);
		res_list->content_size = content_size;
	}
	return (res_list);
}
