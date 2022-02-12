/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:01:38 by jinbkim           #+#    #+#             */
/*   Updated: 2020/07/02 15:44:31 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	char	alpha[128];
	int		i;

	if (argc != 3)
		return (0);
	i = -1;
	while (argv[2][++i])
		alpha[(unsigned char)argv[2][i]] = '1';
	i = -1;
	while (argv[1][++i])
	{
		if (alpha[(unsigned char)argv[1][i]] == '1')
		{
			write(1, &argv[1][i], 1);
			alpha[(unsigned char)argv[1][i]] = '2';
		}
	}
	write(1, "\n", 1);
}
