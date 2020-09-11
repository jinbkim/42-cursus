/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:44:42 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/02 16:15:41 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*read_flag(const char *form, t_info *info)
{
	while (*form == '-' || *form == '0')
	{
		if (*form == '-')
			info->flag = 1;
		else if (*form == '0')
			if (info->flag != 1)
				info->flag = 2;
		form++;
	}
	return (form);
}

const char	*read_width(const char *form, t_info *info, va_list ap)
{
	if (*form == '*' && form++)
		info->width = va_arg(ap, int);
	else
		while (ft_isnum(*form) == 1)
			info->width = info->width * 10 + (*form++ - '0');
	if (info->width < 0)
	{
		info->width *= -1;
		info->flag = 1;
	}
	return (form);
}

const char	*read_prec(const char *form, t_info *info, va_list ap)
{
	form++;
	while (*form == '0')
		form++;
	if (*form == '*' && form++)
		info->prec = va_arg(ap, int);
	if (ft_isnum(*form) == 1)
		while (ft_isnum(*form) == 1 || *form == '0')
			info->prec = info->prec * 10 + (*form++ - '0');
	if (info->prec == 0 && info->flag == 2 && *form != '%')
		info->flag = 0;
	if (info->prec == 0)
		info->point_zero = 1;
	return (form);
}

const char	*show_form_spec(const char *form, t_info *info, va_list ap)
{
	if (*form == 'c' || *form == '%')
		show_c(info, ap, form);
	else if (*form == 's')
		show_s(info, ap);
	else if (*form == 'p')
		show_p(info, ap);
	else if (*form == 'd' || *form == 'i' || *form == 'u'\
			|| *form == 'x' || *form == 'X')
		show_diux(info, ap, form);
	else
		return (NULL);
	return (form);
}
