/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:35:40 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/07 13:36:10 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	if (lst == NULL)
		return (0);
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	return (i + 1);
}
