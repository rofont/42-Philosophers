/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:45:26 by rofontai          #+#    #+#             */
/*   Updated: 2023/09/06 09:00:40 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_message(char *txt, t_philo *ph, t_data *ms)
{
	(void)ms;
	pthread_mutex_lock(&ms->msg);
	if (ms->dead == 0)
	{
		printf ("%ld %d %s\n", get_time(), ph->id, txt);
		pthread_mutex_unlock(&ms->msg);
	}
	pthread_mutex_unlock(&ms->msg);
}

void	f_wait_while(time_t time)
{
	time_t start;

	start = get_time();
	while (1)
	{
		if (get_time() - start >= time)
		break ;
		usleep(50);
	}
}
