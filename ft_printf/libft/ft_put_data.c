/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:19:26 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/02 15:50:35 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdeci(long long data)
{
	if (data < 0)
	{
		if (-(data / 10) != 0)
			ft_putdeci(-(data / 10));
		write(1, &"0123456789"[-(data % 10)], 1);
	}
	else if (data >= 10)
	{
		ft_putdeci(data / 10);
		write(1, &"0123456789"[data % 10], 1);
	}
	else
		write(1, &"0123456789"[data % 10], 1);
}

void	ft_puthex(unsigned long long n)
{
	if (n >= 16)
	{
		ft_puthex(n / 16);
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	}
	else
		write(1, &"0123456789ABCDEF"[n % 16], 1);
}

void	ft_puthex2(unsigned long long n)
{
	if (n >= 16)
	{
		ft_puthex2(n / 16);
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
		write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_put_data(long long data, const char *form)
{
	if (*form == 'd' || *form == 'i' || *form == 'u')
		ft_putdeci(data);
	else if (*form == 'X')
		ft_puthex(data);
	else if (*form == 'x')
		ft_puthex2(data);
}
