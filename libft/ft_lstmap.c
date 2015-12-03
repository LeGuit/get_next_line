/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:27:37 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/26 16:16:30 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res_lst;
	t_list	*tmp_res;
	t_list	*tmp_lst;

	tmp_lst = f(lst);
	if ((res_lst = ft_lstnew(tmp_lst->content, tmp_lst->content_size)))
	{
		tmp_res = res_lst;
		lst = lst->next;
		while (lst)
		{
			tmp_lst = f(lst);
			if (!(tmp_res->next = ft_lstnew(tmp_lst->content,
					tmp_lst->content_size)))
				return (NULL);
			tmp_res = tmp_res->next;
			lst = lst->next;
		}
	}
	return (res_lst);
}
