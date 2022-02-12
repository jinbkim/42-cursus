/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:05:25 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/26 11:19:18 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*data;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(data = (char *)malloc(len + 1)) || ft_strlen(s) < (int)start)
		return (NULL);
	i = -1;
	while (++i < len)
		data[i] = s[start++];
	data[i] = '\0';
	return (data);
}
