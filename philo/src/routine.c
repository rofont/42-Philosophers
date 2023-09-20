/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:33:40 by rofontai          #+#    #+#             */
/*   Updated: 2023/09/20 09:38:29 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->l_fork);
	f_message(FORK, ph, ph->info);
	pthread_mutex_lock(ph->r_fork);
	f_message(FORK, ph, ph->info);
	f_message(EAT, ph, ph->info);
	pthread_mutex_lock(&ph->info->var);
	ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->info->var);
	f_wait_while(ph->info->tt_eat);
	f_message(SLEEP, ph, ph->info);
	pthread_mutex_unlock(ph->r_fork);
	pthread_mutex_unlock(&ph->l_fork);
}

void	*f_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 1)
	{
		f_message(THINK, ph, ph->info);
		f_wait_while(ph->info->tt_eat);
	}
	while (1)
	{
		f_eating(ph);
		pthread_mutex_lock(&ph->info->var);
		if (++ph->meals == ph->info->nb_meals)
			ph->full = 1;
		pthread_mutex_unlock(&ph->info->var);
		f_wait_while(ph->info->tt_sleep);
		if (f_check_is_dead(ph->info) || ph->full == 1)
			return (NULL);
		f_message(THINK, ph, ph->info);
		if (f_check_is_dead(ph->info) || ph->full == 1)
			return (NULL);
	}
	return (arg);
}

void	f_destroy(pthread_t *eater, t_philo *ph, t_data *ms)
{
	int	i;

	i = -1;
	while (++i < ms->nb_philo)
	{
		pthread_join(eater[i], NULL);
		pthread_mutex_destroy(&ph[i].l_fork);
	}
	pthread_mutex_destroy(&ms->msg);
	pthread_mutex_destroy(&ms->var);
	pthread_mutex_destroy(&ms->key);
}

void	f_make_philo(pthread_t *eater, t_philo *ph, t_data *ms)
{
	int	i;

	i = -1;
	if (ms->nb_philo == 1)
	{
		ph[0].last_meal = get_time();
		pthread_create(&eater[0], NULL, &f_routine_alone, &ph[0]);
	}
	else
	{
		while (++i < ms->nb_philo)
		{
			ph[i].last_meal = get_time();
			pthread_create(&eater[i], NULL, &f_routine, &ph[i]);
		}
	}
}

void	f_progress(t_data *ms, t_philo *ph)
{
	pthread_t	eater[250];

	f_make_philo(eater, ph, ms);
	f_who_is_dead(ph, ms);
	f_destroy(eater, ph, ms);
}
