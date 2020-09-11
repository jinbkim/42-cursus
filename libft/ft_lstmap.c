/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:33:51 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/14 02:17:17 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_add;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_add = ft_lstnew(f(lst->content));
	if (new_add == NULL)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	new_list = new_add;
	lst = lst->next;
	while (lst)
	{
		new_add = ft_lstnew(f(lst->content));
		if (new_add == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_add);
		lst = lst->next;
	}
	return (new_list);
}
