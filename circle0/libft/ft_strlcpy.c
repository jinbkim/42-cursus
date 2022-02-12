/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:52:43 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/08 16:39:50 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_size;
	size_t i;

	if (src == NULL || dst == NULL)
		return (0);
	src_size = ft_strlen(src);
	i = -1;
	if (size == 0)
		return (src_size);
	else
	{
		if (src_size >= size - 1)
		{
			while (++i < size - 1)
				dst[i] = src[i];
			dst[i] = '\0';
		}
		else
		{
			while (src[++i])
				dst[i] = src[i];
			dst[i] = '\0';
		}
	}
	return (src_size);
}
