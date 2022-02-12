/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 18:08:55 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/03 23:06:22 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_info(t_info *info)
{
	info->flag = 0;
	info->width = 0;
	info->prec = 0;
	info->point_zero = 0;
	info->re = 0;
}

const char	*read_info(va_list ap, const char *form, int *re_value)
{
	t_info *info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (NULL);
	init_info(info);
	form = read_flag(form, info);
	form = read_width(form, info, ap);
	if (*form == '.')
		form = read_prec(form, info, ap);
	form = show_form_spec(form, info, ap);
	*re_value += info->re;
	free(info);
	info = NULL;
	return (form);
}

int			parse(va_list ap, const char *form)
{
	int	re_value;

	re_value = 0;
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (!(form = read_info(ap, form, &re_value)))
				return (0);
		}
		else if (*form != '%' && ++re_value)
			write(1, form, 1);
		form++;
	}
	return (re_value);
}

int			ft_printf(const char *form, ...)
{
	int		re_value;
	va_list	ap;

	va_start(ap, form);
	re_value = parse(ap, form);
	va_end(ap);
	return (re_value);
}
