/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:47:33 by romain            #+#    #+#             */
/*   Updated: 2023/08/28 22:02:18 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	f_eating(t_philo *ph)
{
	time_t eat;

	pthread_mutex_lock(&ph->l_fork);
	f_message(FORK, ph, ph->info);
	pthread_mutex_lock(ph->r_fork);
	f_message(FORK, ph, ph->info);
	f_message(EAT, ph, ph->info);
	eat = ph->info->tt_eat + get_time();
	while (get_time() < eat)
		usleep(50);
	pthread_mutex_lock(&ph->info->var);
	ph->meals += 1;
	if (ph->meals == ph->info->nb_meals)
	{
		ph->info->full += 1;
	}
	pthread_mutex_unlock(&ph->info->var);
	pthread_mutex_unlock(ph->r_fork);
	pthread_mutex_unlock(&ph->l_fork);
	return (true);
}

