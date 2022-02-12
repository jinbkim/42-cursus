/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:49:58 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/07 13:50:27 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1)) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
