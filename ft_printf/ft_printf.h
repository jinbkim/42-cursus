/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:49:07 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/02 16:49:55 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_info
{
	int			flag;
	int			width;
	int			prec;
	int			point_zero;
	int			re;
}				t_info;

void			show_s(t_info *info, va_list ap);
void			show_s_1(t_info *info, int *size, char *data);
void			show_c(t_info *info, va_list ap, const char *form);
void			show_diux(t_info *info, va_list ap, const char *form);
void			show_diux_1(t_info *info, int *size,\
					long long data, const char *form);
void			show_diux_2(t_info *info, int *size,\
					long long data, const char *form);
void			show_p(t_info *info, va_list ap);
void			init_info(t_info *info);

int				ft_printf(const char *form, ...);
int				parse(va_list ap, const char *form);

const char		*read_info(va_list ap, const char *form, int *re_value);
const char		*read_prec(const char *form, t_info *info, va_list ap);
const char		*read_width(const char *form, t_info *info, va_list ap);
const char		*read_flag(const char *form, t_info *info);
const char		*show_form_spec(const char *form, t_info *info, va_list ap);

#endif
