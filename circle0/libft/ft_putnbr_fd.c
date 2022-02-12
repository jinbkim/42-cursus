/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 13:44:25 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/07 13:44:51 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sign_check(long *n)
{
	if (*n >= 0)
		return (1);
	*n *= -1;
	return (-1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	long	num;

	num = (long)n;
	sign = sign_check(&num);
	if (sign == -1)
		write(fd, "-", 1);
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
		write(fd, &"0123456789"[num % 10], 1);
	}
	else
		write(fd, &"0123456789"[num % 10], 1);
}
