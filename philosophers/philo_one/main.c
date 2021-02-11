/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:46:35 by jinbkim           #+#    #+#             */
/*   Updated: 2021/02/11 18:48:07 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		parse(char **argv)
{
	if ((g_table.num_philo = ft_atoi(argv[1])) <= 1 ||
		(g_table.time_to_die = ft_atoi(argv[2])) <= 0 ||
		(g_table.time_to_eat = ft_atoi(argv[3])) <= 0 ||
		(g_table.time_to_sleep = ft_atoi(argv[4])) <= 0)
		return (1);
	if (argv[5] && (g_table.num_eat = ft_atoi(argv[5])) <= 0)
		return (1);
	else if (!argv[5])
		g_table.num_eat = -1;
	return (0);
}

void	init_table(void)
{
	int		i;

	i = -1;
	while (++i < g_table.num_philo)
	{
		pthread_mutex_init(&g_table.fork[i], NULL);
		g_philos[i].nbr = i + 1;
		g_philos[i].eat = 0;
		g_philos[i].fork1 = i - 1;
		if (!i)
			g_philos[i].fork1 = g_table.num_philo - 1;
		g_philos[i].fork2 = i;
	}
	pthread_mutex_init(&g_table.m_msg, NULL);
	g_table.eat = 0;
	g_table.dead = 0;
	g_table.base_time = get_time();
}

void	init_philos(void)
{
	int		i;

	i = -1;
	while (++i < g_table.num_philo)
	{
		g_philos[i].last_eat = get_time();
		pthread_create(&g_philos[i].tid, NULL, philo_act, &g_philos[i]);
	}
	i = -1;
	while (++i < g_table.num_philo)
		pthread_join(g_philos[i].tid, NULL);
}

void	clean_table(void)
{
	int		i;

	i = -1;
	while (++i < g_table.num_philo)
		pthread_mutex_destroy(&g_table.fork[i]);
	pthread_mutex_destroy(&g_table.m_msg);
	free(g_table.fork);
	free(g_philos);
}

int		main(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6) || parse(argv))
		return (printf("argruments error!"));
	if (!(g_philos = malloc(sizeof(t_philo) * g_table.num_philo)))
		return (printf("philos malloc error!"));
	if (!(g_table.fork = malloc(sizeof(pthread_mutex_t) * g_table.num_philo)))
		return (printf("fork malloc error!"));
	init_table();
	init_philos();
	clean_table();
	return (0);
}
