/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:33:40 by rofontai          #+#    #+#             */
/*   Updated: 2023/09/06 10:38:00 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*f_routine(void *arg)
{
	t_philo *ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
	{
		f_message(THINK, ph, ph->info);
		f_wait_while(ph->info->tt_eat);
	}
	while (ph->meals != ph->info->nb_meals)
	{
		f_eating(ph);
		ph->meals++;
		f_message(SLEEP, ph, ph->info);
		f_wait_while(ph->info->tt_sleep);
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
	{
		ph[i].last_meal = get_time();
		pthread_create(&eater[i], NULL, &f_routine, &ph[i]);
		// printf("ph =%d= time =%ld=\n", ph[i].id, ph[i].last_meal);
	}
}


void	f_progress(t_data *ms, t_philo *ph)
{
	pthread_t eater[1000];

	f_make_philo(eater, ph, ms);
	f_destroy(eater, ph, ms);
}
