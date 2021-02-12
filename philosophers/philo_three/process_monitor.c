/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbkim <jinbkim@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:51:37 by jinbkim           #+#    #+#             */
/*   Updated: 2021/02/12 14:01:26 by jinbkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		kill_process(void)
{
	int		i;

	i = -1;
	while (++i < g_table.num_philo)
		kill(g_philos[i].pid, SIGKILL);
	return (1);
}

void	process_monitor(void)
{
	int		i;
	int		status;
	int		eat;

	eat = 0;
	while (1)
	{
		i = -1;
		while (++i < g_table.num_philo)
		{
			status = -1;
			waitpid(g_philos[i].pid, &status, WNOHANG);
			if (status == 256)
				break ;
			if (status == 0 && ++eat)
				if (eat == g_table.num_philo)
					break ;
		}
		if (i != g_table.num_philo)
		{
			kill_process();
			break ;
		}
	}
}
