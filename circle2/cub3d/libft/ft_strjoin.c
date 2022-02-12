/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:57:36 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/28 11:47:12 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*data;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(data = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		data[i] = s1[i];
	j = -1;
	while (s2[++j])
		data[i + j] = s2[j];
	data[i + j] = '\0';
	return (data);
}
