/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:19:13 by jinbkim           #+#    #+#             */
/*   Updated: 2020/04/21 21:21:18 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		arr_init(int *size, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		size[j] = 0;
		j++;
	}
}