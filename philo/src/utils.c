/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:45:26 by rofontai          #+#    #+#             */
/*   Updated: 2023/09/19 20:59:51 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_message(char *txt, t_philo *ph, t_data *ms)
{
	(void)ms;
	pthread_mutex_lock(&ms->msg);
	if (!f_check_is_dead(ms))
		printf ("%ld %d %s\n", get_time(), ph->id, txt);
	pthread_mutex_unlock(&ms->msg);
}

void	f_wait_while(time_t time)
{
	time_t	start;

	start = get_time();
	while (1)
	{
		if (get_time() - start >= time)
			break ;
		usleep(40);
	}
}

void	f_who_is_dead(t_philo *ph, t_data *ms)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < ms->nb_philo)
		{
			if (ph[i].meals == ms->nb_meals)
				return ;
			else if (get_time() - ph[i].last_meal >= ms->tt_die)
			{
				pthread_mutex_lock(&ms->key);
				ms->dead = 1;
				pthread_mutex_unlock(&ms->key);
				pthread_mutex_lock(&ms->msg);
				printf("%ld %d died\n", get_time(), ph[i].id);
				pthread_mutex_unlock(&ms->msg);
				return ;
			}
			i++;
		}
		usleep(40);
	}
}

bool	f_check_is_dead(t_data *ms)
{
	pthread_mutex_lock(&ms->key);
	if (ms->dead == 1)
	{
		pthread_mutex_unlock(&ms->key);
		return (true);
	}
	pthread_mutex_unlock(&ms->key);
	return (false);
}
