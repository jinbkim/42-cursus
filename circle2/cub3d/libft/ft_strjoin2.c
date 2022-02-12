/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:51:05 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/26 11:19:20 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *buff, char *temp)
{
	char	*data;
	int		i;
	int		j;

	data = (char *)malloc(BUFFER_SIZE + ft_strlen(buff) + ft_strlen(temp) + 1);
	i = -1;
	while (buff[++i])
		data[i] = buff[i];
	j = -1;
	while (temp[++j])
		data[i + j] = temp[j];
	data[i + j] = '\0';
	free(buff);
	buff = NULL;
	return (data);
}
