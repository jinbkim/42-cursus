/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_act.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:51:02 by jinbkim           #+#    #+#             */
/*   Updated: 2021/02/11 18:53:02 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		msg(t_philo *philo, int msg, unsigned long cur)
{
	pthread_mutex_lock(&g_table.m_msg);
	if (g_table.dead)
	{
		pthread_mutex_unlock(&g_table.m_msg);
		return (1);
	}
	printf("%lu %d", cur - g_table.base_time, philo->nbr);
	if (msg == TAKEN_FORK)
		printf(" has taken a fork\n");
	else if (msg == EATING)
	{
		printf(" is eating\n");
		philo->last_eat = cur;
	}
	else if (msg == SLEEPING)
		printf(" is sleeping\n");
	else if (msg == THINKING)
		printf(" is thinking\n");
	else if (msg == DEAD)
	{
		printf(" died\n");
		g_table.dead = 1;
	}
	pthread_mutex_unlock(&g_table.m_msg);
	return (0);
}

void	*philo_monitor(void *phi)
{
	t_philo			*philo;
	unsigned long	cur;

	philo = (t_philo *)phi;
	while (1)
	{
		if (philo->eat == g_table.num_eat)
			break ;
		cur = get_time();
		if (g_table.time_to_die < cur - philo->last_eat)
		{
			msg(philo, DEAD, cur);
			return (NULL);
		}
		less_error_sleep(1);
	}
	return (NULL);
}

int		eat(t_philo *philo)
{
	pthread_mutex_lock(&g_table.fork[philo->fork1]);
	msg(philo, TAKEN_FORK, get_time());
	pthread_mutex_lock(&g_table.fork[philo->fork2]);
	msg(philo, TAKEN_FORK, get_time());
	msg(philo, EATING, get_time());
	less_error_sleep(g_table.time_to_eat);
	pthread_mutex_unlock(&g_table.fork[philo->fork1]);
	pthread_mutex_unlock(&g_table.fork[philo->fork2]);
	philo->eat++;
	if (philo->eat == g_table.num_eat)
	{
		g_table.eat++;
		return (1);
	}
	return (0);
}

void	*philo_act(void *phi)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)phi;
	if (!(philo->nbr % 2))
		less_error_sleep(1);
	pthread_create(&tid, NULL, philo_monitor, philo);
	while (1)
	{
		if (eat(philo))
			break ;
		if (msg(philo, SLEEPING, get_time()))
			break ;
		less_error_sleep(g_table.time_to_sleep);
		if (msg(philo, THINKING, get_time()))
			break ;
	}
	pthread_join(tid, NULL);
	return (NULL);
}
