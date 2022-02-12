/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_leng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:19:18 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/02 15:42:04 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		leng(long long n, const char *form)
{
	int i;

	if (n == 0)
		return (1);
	i = 0;
	if (*form == 'd' || *form == 'i' || *form == 'u')
		while (n != 0 && ++i)
			n /= 10;
	else if (*form == 'x' || *form == 'X')
		while (n != 0 && ++i)
			n /= 16;
	return (i);
}

int		hex_leng_2(unsigned long long n, int point_zero)
{
	int i;

	i = 0;
	if (n == 0)
	{
		if (point_zero)
			return (0);
		else
			return (1);
	}
	while (n != 0 && ++i)
		n /= 16;
	return (i);
}
