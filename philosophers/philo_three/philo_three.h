/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:06:03 by jinbkim           #+#    #+#             */
/*   Updated: 2021/02/12 13:08:30 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>

# define TAKEN_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DEAD		4

typedef struct		s_table
{
	int				num_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				num_eat;

	unsigned long	base_time;
	int				eat;
	int				dead;
	sem_t			*enter;
	sem_t			*m_msg;
}					t_table;

typedef struct		s_philo
{
	int				nbr;
	int				eat;
	unsigned long	last_eat;
	pid_t			pid;
}					t_philo;

t_table				g_table;
t_philo				*g_philos;

void				*philo_act(void *philo);
void				*philo_monitor(void *philo);
void				init_philos(void);
void				process_monitor(void);
void				init_table(void);
void				less_error_sleep(unsigned long itime);
void				clean_table(void);

int					ft_atoi(char *str);
int					parse(char **argv);
int					msg(t_philo *philo, int msg, unsigned long current_time);
int					eat(t_philo *philo);
int					kill_process(void);

unsigned long		get_time(void);
#endif
