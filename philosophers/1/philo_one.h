#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h> 
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

	unsigned long	base_time;  // 베이스시간. 기준이되는시간
	int				eat;  // 다먹은사람의 수. 옵션이 있을떄만 의미가 있음
	int				dead;  // 죽은살마의 수. 사실 1만되도 끄기때문에 0, 1 밖에 안씀
	pthread_mutex_t	*fork;  //  포크의수. 
	pthread_mutex_t	m_msg;  // 메시지를 출력할때. 순서대로. 
}					t_table;

typedef struct		s_philo
{
	int				nbr;  // 인덱스
	int				fork1;
	int				fork2;
	int				eat;  // 몇번먹었는지
	unsigned long	last_eat;  // 최근에 언제밥
	pthread_t		tid;  // 쓰레드 관리할떄
}					t_philo;

t_table		table;
t_philo		*philos;

void				*philo_act(void *philo);
void				*philo_monitor(void *philo);
void				clean_table(void);
void				less_error_sleep(unsigned long time);
void				init_philos(void);
void				init_table(void);

int					ft_atoi(char *str);
int					parse(char **argv);
int					msg(t_philo *philo, int msg, unsigned long cur);
int					eat(t_philo *philo);


unsigned long		get_time(void);

#endif
