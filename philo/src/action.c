/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:47:33 by romain            #+#    #+#             */
/*   Updated: 2023/08/31 15:31:58 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool f_check_is_full(t_philo *ph)
{
	pthread_mutex_lock(&ph->info->var);
	if (ph->info->full == ph->info->nb_philo)
	{
		pthread_mutex_unlock(&ph->info->var);
		return (true);
	}
	pthread_mutex_unlock(&ph->info->var);
	return (false);
}

bool f_check_is_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->info->var);
	if (ph->info->dead == 1)
	{
		pthread_mutex_unlock(&ph->info->var);
		return (true);
	}
	pthread_mutex_unlock(&ph->info->var);
	return (false);
}

bool	f_eating(t_philo *ph)
{
	time_t eat;

	pthread_mutex_lock(&ph->l_fork);
	f_message(FORK, ph, ph->info);
	pthread_mutex_lock(ph->r_fork);
	f_message(FORK, ph, ph->info);
	f_message(EAT, ph, ph->info);
	eat = ph->info->tt_eat + get_time();
	ph->last_meal = ph->info->tt_die + get_time();
	while (get_time() < eat)
	{
		if (ph->last_meal < get_time())
		{
			pthread_mutex_lock(&ph->info->var);
			ph->info->dead = 1;
			pthread_mutex_unlock(&ph->info->var);
			f_message(DIED, ph, ph->info);
			pthread_mutex_unlock(ph->r_fork);
			pthread_mutex_unlock(&ph->l_fork);
			return (false);
		}
	}
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

bool	f_sleeping(t_philo *ph)
{
	time_t sleep;

	sleep = ph->info->tt_sleep + get_time();
	f_message(SLEEP, ph, ph->info);
	while (get_time() < sleep)
	{
		if (ph->last_meal < get_time())
		{
			pthread_mutex_lock(&ph->info->var);
			ph->info->dead = 1;
			pthread_mutex_unlock(&ph->info->var);
			f_message(DIED, ph, ph->info);
			return (false);
		}
		usleep(50);
	}
	return (true);
}

bool	f_thinking(t_philo *ph)
{
	f_message(THINK, ph, ph->info);
	if (!f_monitoring(ph, ph->last_meal))
		return (false);
	return (true);
}
