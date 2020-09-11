/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:25:16 by jinbkim           #+#    #+#             */
/*   Updated: 2020/05/02 16:49:16 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	arr_init(int *size, int i);
void	ft_putdeci(long long data);
void	ft_puthex(unsigned long long n);
void	ft_puthex2(unsigned long long n);
void	ft_put_data(long long data, const char *form);

char	*ft_strdup(const char *s1);

int		hex_leng(unsigned long long n);
int		deci_leng(long long n);
int		hex_leng_2(unsigned long long n, int point_zero);
int		leng(long long n, const char *form);
int		ft_isnum(char c);
int		ft_strlen(const char *s);

#endif
