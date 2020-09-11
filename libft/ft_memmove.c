/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:41:03 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/07 13:41:21 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*pdest;
	const char	*psrc;

	i = -1;
	pdest = (char *)dest;
	psrc = (const char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (psrc >= pdest)
		while (++i < n)
			pdest[i] = psrc[i];
	else
		while (++i < n)
			pdest[n - i - 1] = psrc[n - i - 1];
	return (pdest);
}
