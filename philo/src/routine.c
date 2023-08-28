/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:33:40 by rofontai          #+#    #+#             */
/*   Updated: 2023/08/28 15:36:07 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*f_routine(void *arg)
{
	t_philo *ph;


	ph = (t_philo *)arg;

	if (ph->id % 2 == 0)
		usleep(ph->info->tt_eat * 1000 / 2);
	while (get_time() < 1000)
	{
		pthread_mutex_lock(&ph->l_fork);
		f_message(FORK, ph, ph->info);
		pthread_mutex_lock(ph->r_fork);
		f_message(FORK, ph, ph->info);
		f_message(EAT, ph, ph->info);
		time_t eat = ph->info->tt_eat + get_time();
		while (get_time() < eat)
			usleep(100);
		pthread_mutex_unlock(ph->r_fork);
		pthread_mutex_unlock(&ph->l_fork);
		time_t sleep = ph->info->tt_sleep + get_time();
		f_message(SLEEP, ph, ph->info);
		while (get_time() < sleep)
			usleep(100);
		f_message(THINK, ph, ph->info);
	}
		/*
		take fork L
		take fork r
		EAT during tt_eat
		pose fork r
		pose fork l
		sleep during tt sleep
		think during take fork r
		take fork l
		*/
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
	{
		ph[i].last_meal = get_time();
		pthread_create(&eater[i], NULL, &f_routine, &ph[i]);
	}
}


void	f_progress(t_data *ms, t_philo *ph)
{
	pthread_t eater[1000];

	f_make_philo(eater, ph, ms);
	f_destroy(eater, ph, ms);
}
