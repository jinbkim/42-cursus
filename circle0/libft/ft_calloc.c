/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 21:07:44 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/07 12:33:04 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char *data;

	data = malloc(size * num);
	if (data == NULL)
		return (NULL);
	ft_memset(data, 0, size * num);
	return (data);
}
