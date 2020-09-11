/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_deci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:58:23 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/26 11:06:30 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		char_to_deci(char *s, int idx)
{
	int result;

	result = 0;
	while (ft_isdigit(s[idx]))
		result = (result * 10) + (s[idx++] - '0');
	return (result);
}
