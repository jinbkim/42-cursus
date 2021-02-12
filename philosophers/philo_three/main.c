/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:46:35 by jinbkim           #+#    #+#             */
/*   Updated: 2021/02/12 13:04:41 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
		g_philos[i].nbr = i + 1;
		g_philos[i].eat = 0;
	}
	g_table.eat = 0;
	g_table.dead = 0;
	g_table.base_time = get_time();
	g_table.enter = sem_open("/enter", O_CREAT | O_EXCL, 0777, g_table.num_philo / 2);
	g_table.m_msg = sem_open("/m_msg", O_CREAT | O_EXCL, 0777, 1);
	sem_unlink("/enter");
	sem_unlink("/m_msg");
}

void	init_philos(void)
{
	int		i;

	i = -1;
	while (++i < g_table.num_philo)
	{
		g_philos[i].pid = fork();
		if (!g_philos[i].pid)
			break ;
	}
	if (i != g_table.num_philo)
	{
		philo_act(&g_philos[i]);
		exit(0);
	}
	else
		process_monitor();
}

void	clean_table(void)
{
	sem_close(g_table.enter);
	sem_close(g_table.m_msg);
	free(g_philos);
}

int		main(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6) || parse(argv))
		return (printf("argruments error!"));
	if (!(g_philos = malloc(sizeof(t_philo) * g_table.num_philo)))
		return (printf("philos malloc error!"));
	init_table();
	init_philos();
	clean_table();
	return (0);
}
