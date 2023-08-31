/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:45:26 by rofontai          #+#    #+#             */
/*   Updated: 2023/08/31 15:37:36 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	f_message(char *txt, t_philo *ph, t_data *ms)
{
	(void)ms;
	pthread_mutex_lock(&ms->msg);
	if (ms->dead == 0)
	{
		if(ph->alive == false)
		{
			ms->dead = 1;
			printf ("%ld %d %s\n", get_time(), ph->id, DIED);
			pthread_mutex_unlock(&ms->msg);
			return (1);
		}
		printf ("%ld %d %s\n", get_time(), ph->id, txt);
		pthread_mutex_unlock(&ms->msg);
		return (0);
	}
	pthread_mutex_unlock(&ms->msg);
	return (1);
}

 bool	f_monitoring(t_philo *ph, time_t limit)
 {
	while (get_time() < limit)
	{
		if (get_time() > ph->last_meal)
		{
			ph->alive = false;
			if (f_check_is_dead(ph))
			return (false);
			f_message(DIED, ph, ph->info);
		}
		usleep(100);
	}
	return (true);
 }
