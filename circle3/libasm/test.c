/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:08:39 by jinbkim           #+#    #+#             */
/*   Updated: 2020/08/01 15:52:25 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libasm.h"

int		main(void)
{
	char	arr_str1[100];
	char	arr_str2[100];
	char	arr_str3[100];
	char	arr_str4[100];
	char	arr_str5[100];
	char	arr_str6[100];
	char	arr_str7[100];
	char	arr_str8[100];
	char	*point_str1;
	char	*point_str2;
	int		ret1;

	printf("----- ft_read(1, arr_str1, 5) -----\n");
	printf("return : %zd, str : %s\n", ft_read(0, arr_str1, 5), arr_str1);
	getchar();
	printf("----- read(1, arr_str2, 5) -----\n");
	printf("return : %zd, str : %s\n", read(0, arr_str2, 5), arr_str2);
	getchar();
	printf("----- ft_read(-1, arr_str4, 5) -----\n");
	printf("return : %zd, str : %s\n", ft_read(-1, arr_str4, 5), arr_str4);
	printf("----- read(-1, arr_str4, 5) -----\n");
	printf("return : %zd, str : %s\n", read(-1, arr_str4, 5), arr_str4);
	printf("----------------------------------------\n");
	printf("----- ft_strcmp(hello,hello)) -----\n");
	if ((ft_strcmp("hello", "hello")))
		printf("differnt!\n");
	else
		printf("same!\n");
	printf("----- strcmp(hello,hello)) -----\n");
	if ((ret1 = strcmp("hello", "hello")))
		printf("differnt!\n");
	else
		printf("same!\n");
	printf("----- ft_strcmp(hello,hell)) -----\n");
	if ((ret1 = ft_strcmp("hello", "hell")))
		printf("differnt!\n");
	else
		printf("same!\n");
	printf("----- strcmp(hello,hell)) -----\n");
	if ((ret1 = strcmp("hello", "hell")))
		printf("differnt!\n");
	else
		printf("same!\n");
	printf("----------------------------------------\n");
	printf("----- ft_strcpy(arr_str5, hello) -----\n");
	printf("return : %s, str : %s\n", ft_strcpy(arr_str5, "hello"), arr_str5);
	printf("----- strcpy(arr_str6, hello) -----\n");
	printf("return : %s, str : %s\n", strcpy(arr_str6, "hello"), arr_str6);
	printf("----------------------------------------\n");
	printf("----- ft_strdup(hello) -----\n");
	printf("str : %s\n", point_str1 = ft_strdup("hello"));
	printf("----- strdup(hello) -----\n");
	printf("str : %s\n", point_str2 = strdup("hello"));
	printf("----------------------------------------\n");
	printf("----- ft_strlen(hello) -----\n");
	printf("str : %ld\n", ft_strlen("hello"));
	printf("----- strlen(hello) -----\n");
	printf("str : %ld\n", strlen("hello"));
	printf("----------------------------------------\n");
	printf("----- ft_write(1, hello\\n, 6) -----\n");
	ft_write(1, "hello\n", 6);
	printf("----- write(1, hello\\n, 6) -----\n");
	write(1, "hello\n", 6);
	printf("----- ft_write(-1, hello\\n, 6) -----\n");
	ft_write(-1, "hello\n", 6);
	printf("----- write(-1, hello\\n, 6) -----\n");
	write(-1, "hello\n", 6);
	printf("----------------------------------------\n");
	free(point_str1);
	free(point_str2);
}
