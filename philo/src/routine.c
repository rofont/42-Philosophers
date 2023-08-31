/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:33:40 by rofontai          #+#    #+#             */
/*   Updated: 2023/08/31 15:30:41 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*f_routine(void *arg)
{
	t_philo *ph;

	ph = (t_philo *)arg;
	ph->last_meal = ph->info->tt_die;
	if (ph->id % 2 == 0)
		usleep(1000);
	while (ph->meals != ph->info->nb_meals)
	{
		if (!f_eating(ph))
			break;
		if (!f_sleeping(ph))
			break;
		if (!f_thinking(ph))
			break;
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
