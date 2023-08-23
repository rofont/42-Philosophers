/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:45:26 by rofontai          #+#    #+#             */
/*   Updated: 2023/08/23 13:35:43 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_message(char *txt, t_philo *ph, t_data *ms)
{
	pthread_mutex_lock(&ms->msg);
	printf ("%ldms %d %s\n", get_time(), ph->id, txt);
	pthread_mutex_unlock(&ms->msg);
}

bool	f_monitor_man(t_philo *ph, t_data *ms)
{
	int i;

	i = 0;
	while (i < ms->nb_philo)
	{
		if (!ph[i].alive)
			return (false);
		else if (ph[i].meals == ms->nb_meals)
		{
			ms->full++;
			if (ms->full == ms->nb_philo)
				return (false);
		}
		i++;
	}
	return (true);
}
