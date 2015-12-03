/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwoodwar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:26:23 by gwoodwar          #+#    #+#             */
/*   Updated: 2015/11/26 13:47:10 by gwoodwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nlst;
	t_list	*lst;

	lst = *alst;
	while (lst)
	{
		nlst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nlst;
	}
	*alst = NULL;
}
