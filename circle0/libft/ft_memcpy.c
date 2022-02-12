/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:40:13 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/08 19:37:05 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *des, const void *src, size_t n)
{
	size_t		i;
	char		*pdes;
	const char	*psrc;

	pdes = (char *)des;
	psrc = (const char *)src;
	i = -1;
	if (src == NULL && des == NULL)
		return (NULL);
	while (++i < n)
		pdes[i] = psrc[i];
	return (pdes);
}
