/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:36:32 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/08 19:31:01 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = (unsigned char *)dest;
	psrc = (const unsigned char *)src;
	i = -1;
	while (++i < n)
	{
		pdest[i] = psrc[i];
		if (psrc[i] == (unsigned char)c)
			return (pdest + i + 1);
	}
	return (NULL);
}
