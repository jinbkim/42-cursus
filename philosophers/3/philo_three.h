/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemin <jaemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:39:31 by jaemin            #+#    #+#             */
/*   Updated: 2020/12/23 14:21:20 by jaemin           ###   ########.fr       */
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
	sem_t			*write_msg;
}					t_table;

typedef struct		s_philo
{
	int				nbr;
	int				eat;
	unsigned long	last_eat;
	pid_t			pid;
}					t_philo;

t_philo		*philos;
t_table		table;

int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(char *str);
int					ft_strlen(const char *s);
char				*ft_itoa(int n);

int					parse(char **argv);
int					parse_num(char *num, int idx);
int					parse_check(void);

int					msg(t_philo *philo, int msg, unsigned long current_time);
int					error(char *str);
int					error_arg(int i);

void				*philo_act(void *philo);
void				*philo_monitor(void *philo);
int					eat(t_philo *philo);
void				init_philos(void);
int					kill_process(void);
void				process_monitor(void);

void				init_table(void);
void				init_sem(void);
void				clear_sem(void);

unsigned long		get_time(void);
void				less_error_sleep(unsigned long itime);

#endif
