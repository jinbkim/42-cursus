/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:48:38 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/26 11:19:22 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*data;
	int		i;

	data = (char *)malloc(ft_strlen(s) + 2);
	if (data == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		data[i] = s[i];
	data[i] = '\0';
	data[i + 1] = '\0';
	return (data);
}
