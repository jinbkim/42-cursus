/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 19:22:45 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/24 13:22:46 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *s)
{
	unsigned int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	unsigned int	i;
	char			*data;

	if (!s)
		return (NULL);
	data = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (data == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		data[i] = s[i];
	data[i] = '\0';
	return (data);
}

char	*ft_strjoin(char *buff, char *temp)
{
	unsigned int	i;
	unsigned int	j;
	char			*data;

	if (!buff || !temp)
		return (NULL);
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
