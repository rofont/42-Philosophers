/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:33:40 by rofontai          #+#    #+#             */
/*   Updated: 2023/08/28 22:16:02 by romain           ###   ########.fr       */
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


void	*f_routine(void *arg)
{
	t_philo *ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(1000);
	while (!f_check_is_full(ph))
	{
		f_eating(ph);
		time_t sleep = ph->info->tt_sleep + get_time();
		f_message(SLEEP, ph, ph->info);
		while (get_time() < sleep)
			usleep(50);
		f_message(THINK, ph, ph->info);
	}
	return (arg);
}

void	f_destroy(pthread_t *eater,t_philo *ph, t_data *ms)
{
	int i;

	i = -1;
	while(++i < ms->nb_philo)
		pthread_join(eater[i], NULL);
	pthread_mutex_destroy(&ms->msg);
	pthread_mutex_destroy(&ms->var);
	pthread_mutex_destroy(&ph->l_fork);
}

void	f_make_philo(pthread_t *eater, t_philo *ph, t_data *ms)
{
	int i;

	i = -1;
	while (++i < ms->nb_philo)
		pthread_create(&eater[i], NULL, &f_routine, &ph[i]);
	get_time();
}


void	f_progress(t_data *ms, t_philo *ph)
{
	pthread_t eater[1000];

	f_make_philo(eater, ph, ms);
	f_destroy(eater, ph, ms);
}
