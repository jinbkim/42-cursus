/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 20:54:11 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/09 19:37:51 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_sign(const char *str)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		sign = 0;
	return (sign);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		result;
	char	diff;
	int		sign;

	if (*str == '\0')
		return (0);
	i = 0;
	result = 0;
	diff = '0' - 0;
	sign = check_sign(str);
	while (str[i] < '0' || str[i] > '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - diff);
		i++;
	}
	return (sign * result);
}
