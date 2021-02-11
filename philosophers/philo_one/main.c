#include "philo_one.h"

int		parse(char **argv)
{
	if ((table.num_philo = ft_atoi(argv[1])) <= 1 ||
		(table.time_to_die = ft_atoi(argv[2])) <= 0 ||
		(table.time_to_eat = ft_atoi(argv[3])) <= 0 ||
		(table.time_to_sleep = ft_atoi(argv[4])) <= 0)
		return (1);
	if (argv[5] && (table.num_eat = ft_atoi(argv[5])) <= 0)
		return (1);
	else if (!argv[5])
		table.num_eat = -1;
	return (0);
}

void	init_table(void)
{
	int		i;

	i = -1;
	while (++i < table.num_philo)
	{
		pthread_mutex_init(&table.fork[i], NULL);
		philos[i].nbr = i+1;
		philos[i].eat = 0;
		philos[i].fork1 = i-1;
		if (!i)
			philos[i].fork1 = table.num_philo - 1;
		philos[i].fork2 = i;
	}
	pthread_mutex_init(&table.m_msg, NULL);
	table.eat = 0;
	table.dead = 0;
	table.base_time = get_time();
}

void	init_philos(void)
{
	int		i;

	i = -1;
	while (++i < table.num_philo)
	{
		philos[i].last_eat = get_time();
		pthread_create(&philos[i].tid, NULL, philo_act, &philos[i]);
	}
	i = -1;
	while (++i < table.num_philo)
		pthread_join(philos[i].tid, NULL);
}

void	clean_table(void)
{
	int		i;

	i = -1;
	while (++i < table.num_philo)
		pthread_mutex_destroy(&table.fork[i]);
	pthread_mutex_destroy(&table.m_msg);
	free(table.fork);
	free(philos);
}

int		main(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6) || parse(argv))
		return (printf("argruments error!"));
	if (!(philos = malloc(sizeof(t_philo) * table.num_philo)))
		return (printf("philos malloc error!"));
	if (!(table.fork = malloc(sizeof(pthread_mutex_t) * table.num_philo)))
		return (printf("fork malloc error!"));
	init_table();
	init_philos();
	clean_table();
	return (0);
}