#include "philo_one.h"

int		msg(t_philo *philo, int msg, unsigned long cur)
{
	pthread_mutex_lock(&table.m_msg);
	if (table.dead)
	{
		pthread_mutex_unlock(&table.m_msg);
		return (1);
	}
	printf("%lu %d", cur - table.base_time, philo->nbr);
	if (msg == TAKEN_FORK)
		printf(" has taken a fork\n");
	else if (msg == EATING)
	{
		printf(" is eating\n");
		philo->last_eat = cur;
	}
	else if (msg == SLEEPING)
		printf(" is sleeping\n");
	else if(msg == THINKING)
		printf(" is thinking\n");
	else if (msg == DEAD)
		printf(" died\n");
	pthread_mutex_unlock(&table.m_msg);
	return (0);
}

void	*philo_monitor(void *phi)
{
	t_philo			*philo;
	unsigned long	cur;

	philo = (t_philo *)phi;
	while (1)
	{
		if (philo->eat == table.num_eat)
			break ;
		cur = get_time();
		if (table.time_to_die < cur - philo->last_eat)
		{
			table.dead = 1;
			msg(philo, DEAD, cur);
			return (NULL);
		}
		less_error_sleep(1);
	}
	return (NULL);
}

int		eat(t_philo *philo)
{
	pthread_mutex_lock(&table.fork[philo->fork1]);
	msg(philo, TAKEN_FORK, get_time());
	pthread_mutex_lock(&table.fork[philo->fork2]);
	msg(philo, TAKEN_FORK, get_time());
	msg(philo, EATING, get_time());
	less_error_sleep(table.time_to_eat);
	pthread_mutex_unlock(&table.fork[philo->fork1]);
	pthread_mutex_unlock(&table.fork[philo->fork2]);
	philo->eat++;
	if (philo->eat == table.num_eat)
	{
		table.eat++;
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
		less_error_sleep(table.time_to_sleep);
		if (msg(philo, THINKING, get_time()))
			break ;
	}
	pthread_join(tid, NULL);
	return (NULL);
}