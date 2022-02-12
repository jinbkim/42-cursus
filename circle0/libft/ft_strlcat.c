/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:52:04 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/14 20:29:46 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	result1;
	size_t	result2;

	j = -1;
	result1 = ft_strlen(src) + ft_strlen(dst);
	result2 = ft_strlen(src) + size;
	if (size > ft_strlen(dst))
	{
		i = ft_strlen(dst);
		while (i + (++j) < size - 1 && src[j])
			dst[i + j] = src[j];
		dst[i + j] = '\0';
		return (result1);
	}
	return (result2);
}
