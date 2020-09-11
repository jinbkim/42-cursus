/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_cps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:18:55 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/02 15:37:47 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	show_c(t_info *info, va_list ap, const char *form)
{
	int		i;
	char	data;

	if (*form == 'c')
		data = va_arg(ap, int);
	else
		data = '%';
	i = -1;
	if (info->flag == 2)
		while (++i < info->width - 1)
			write(1, &"0", 1);
	if (info->flag == 0)
		while (++i < info->width - 1)
			write(1, &" ", 1);
	if (!(info->point_zero && data == 0))
		write(1, &data, 1);
	(info->re)++;
	i = -1;
	if (info->flag == 1)
		while (++i < info->width - 1)
			write(1, &" ", 1);
	i = -1;
	while (++i < info->width - 1)
		(info->re)++;
}

void	show_p(t_info *info, va_list ap)
{
	unsigned long	data;
	int				i;

	data = va_arg(ap, unsigned long);
	i = -1;
	if (info->flag != 1)
		while (++i < info->width - hex_leng_2(data, info->point_zero) - 2)
			write(1, &" ", 1);
	write(1, &"0x", 2);
	if (!(data == 0 && info->point_zero))
		ft_puthex2(data);
	if (info->flag == 1)
		while (++i < info->width - hex_leng_2(data, info->point_zero) - 2)
			write(1, &" ", 1);
	info->re += 2 + hex_leng_2(data, info->point_zero);
	i = -1;
	while (++i < info->width - hex_leng_2(data, info->point_zero) - 2)
		(info->re)++;
}

void	show_s_1(t_info *info, int *size, char *data)
{
	if (info->width <= info->prec && info->prec <= ft_strlen(data))
		size[0] = info->prec;
	else if (info->width <= ft_strlen(data) && ft_strlen(data) <= info->prec)
		size[0] = ft_strlen(data);
	else if (info->prec <= info->width && info->prec <= ft_strlen(data))
	{
		size[0] = info->prec;
		size[1] = info->width - info->prec;
	}
	else if (ft_strlen(data) <= info->width && ft_strlen(data) <= info->prec)
	{
		size[0] = ft_strlen(data);
		size[1] = info->width - ft_strlen(data);
	}
	if (info->point_zero)
	{
		size[0] = 0;
		size[1] = info->width;
	}
}

void	show_s(t_info *info, va_list ap)
{
	char	*data;
	int		size[2];
	int		i;

	arr_init(size, 2);
	data = ft_strdup(va_arg(ap, char *));
	if (data == NULL)
		data = ft_strdup("(null)");
	if (info->prec <= 0)
		info->prec = ft_strlen(data);
	show_s_1(info, size, data);
	i = -1;
	if (info->flag != 1)
		while (++i < size[1])
			write(1, &" ", 1);
	write(1, data, size[0]);
	if (info->flag == 1)
		while (++i < size[1])
			write(1, &" ", 1);
	info->re += size[0];
	i = -1;
	while (++i < size[1])
		(info->re)++;
	free(data);
	data = NULL;
}
