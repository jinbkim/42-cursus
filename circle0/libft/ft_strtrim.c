/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 14:00:35 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/05 21:14:10 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		have_set(char c, char const *set)
{
	int i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	str = (char *)s1;
	while (str[i] && have_set(str[i], set))
		i++;
	while (j > 0 && have_set(str[j], set))
		j--;
	if (j <= i)
		str = ft_strdup("\0");
	else
		str = ft_substr(s1, i, j - i + 1);
	return (str);
}
