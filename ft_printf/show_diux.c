/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_diux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:18:41 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/02 16:35:11 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	show_diux_1(t_info *info, int *size, long long data, const char *form)
{
	if (info->flag == 2)
	{
		if (leng(data, form) <= info->width && info->prec <= leng(data, form))
			size[1] = info->width - leng(data, form);
		else if (info->width < info->prec && leng(data, form) <= info->prec)
			size[1] = info->prec - leng(data, form);
		else if (info->prec <= info->width && leng(data, form) <= info->prec)
		{
			size[0] = info->width - info->prec;
			size[1] = info->prec - leng(data, form);
		}
		if (data < 0 && info->prec < leng(data, form))
			size[1]--;
	}
	else
	{
		size[1] = info->prec - leng(data, form);
		if (size[1] < 0)
			size[1] = 0;
		size[0] = info->width - size[1] - leng(data, form);
		if (data == 0 && info->point_zero)
			size[0]++;
	}
	if (data < 0)
		size[0]--;
}

void	show_diux_2(t_info *info, int *size, long long data, const char *form)
{
	int i;

	i = -1;
	while (info->flag != 1 && ++i < size[0])
		write(1, &" ", 1);
	if (data < 0 && ++(info->re))
		write(1, &"-", 1);
	i = -1;
	while (++i < size[1])
	{
		write(1, &"0", 1);
		(info->re)++;
	}
	if (!(info->point_zero == 1 && data == 0))
	{
		ft_put_data(data, form);
		info->re += leng(data, form);
	}
	i = -1;
	while (info->flag == 1 && ++i < size[0])
		write(1, &" ", 1);
	i = -1;
	while (++i < size[0])
		(info->re)++;
}

void	show_diux(t_info *info, va_list ap, const char *form)
{
	long long	data;
	int			size[2];

	data = 0;
	if (*form == 'u' || *form == 'x' || *form == 'X')
		data = va_arg(ap, unsigned int);
	else if (*form == 'd' || *form == 'i')
		data = va_arg(ap, int);
	arr_init(size, 2);
	if (info->prec <= leng(data, form))
	{
		if (info->prec > 0 && info->flag == 2)
			info->flag = 0;
		info->prec = leng(data, form) - 1;
	}
	show_diux_1(info, size, data, form);
	show_diux_2(info, size, data, form);
}
