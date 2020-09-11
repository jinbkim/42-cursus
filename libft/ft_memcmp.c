/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:38:24 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/09 19:29:55 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (n == 0)
		return (0);
	i = -1;
	p1 = (unsigned char *)ptr1;
	p2 = (unsigned char *)ptr2;
	while (++i < n - 1)
		if (p1[i] != p2[i])
			return ((int)p1[i] - p2[i]);
	return ((int)p1[i] - p2[i]);
}
