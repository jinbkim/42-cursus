/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 19:36:34 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/02 16:05:40 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*data;
	int		i;

	// because of ft_charjoin, allocate 1 more memory
	data = (char *)malloc(ft_strlen(s) + 2);
	if (!data)
		return (NULL);
	i = -1;
	while (s[++i])
		data[i] = s[i];
	data[i] = '\0';
	return (data);
}

char	*ft_charjoin(char *buff, char *temp)
{
	char	*data;

	data = ft_strdup(buff);
	data[ft_strlen(buff)] = *temp;
	data[ft_strlen(buff) + 1] = '\0';
	free(buff);
	buff = NULL;
	return (data);
}

int		buff_to_line(char *buff, char **line)
{
	*line = ft_strdup(buff);
	free(buff);
	buff = NULL;
	return (1);
}

int		get_next_line(char **line)
{
	char	*buff;
	char	temp;
	int		ret;

	if (!line)
		return (-1);
	buff = ft_strdup("\0");
	while ((ret = read(0, &temp, 1)) > 0)  // read 1 byte
	{
		if (temp == '\n')
			return (buff_to_line(buff, line));
		buff = ft_charjoin(buff, &temp);
	}
	buff_to_line(buff, line);
	if (ret < 0)
		return (-1);
	return (0);
}
