/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:47:33 by romain            #+#    #+#             */
/*   Updated: 2023/09/06 09:18:07 by rofontai         ###   ########.fr       */
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
	f_wait_while(ph->info->tt_eat);
	ph->last_meal = get_time();
	pthread_mutex_unlock(ph->r_fork);
	pthread_mutex_unlock(&ph->l_fork);
}
