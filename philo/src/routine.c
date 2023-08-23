/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:33:40 by rofontai          #+#    #+#             */
/*   Updated: 2023/08/23 11:03:21 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*f_routine(void *arg)
{
	t_philo *ph;
	time_t time;
	int i;

	i = 0;
	time = get_time();
	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(500);
	while (get_time() <= 1000)
	{
		f_message(THINK, ph, ph->info);
	}
	return (arg);
}

void	f_destroy(pthread_t *eater, t_data *ms)
{
	int i;

	i = -1;
	while(++i < ms->nb_philo)
		pthread_join(eater[i], NULL);
	pthread_mutex_destroy(&ms->lock);
}



void	f_make_philo(pthread_t *eater, t_philo *ph, t_data *ms)
{
	int i;

	i = -1;
	while (++i < ms->nb_philo)
		pthread_create(&eater[i], NULL, &f_routine, &ph[i]);
}


void	f_progress(t_data *ms, t_philo *ph)
{
	pthread_t eater[1000];

	f_make_philo(eater, ph, ms);
	f_destroy(eater, ms);
}