/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:22:03 by romain            #+#    #+#             */
/*   Updated: 2023/08/08 20:13:00 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	f_init_meta(t_meta *ms, int ac, char **av)
{
	ms->nb_philos = f_atol(av[1]);
	ms->tt_die = f_atol(av[2]);
	ms->tt_eat = f_atol(av[3]);
	ms->tt_sleep = f_atol(av[4]);
	if (ac == 6)
		ms->nb_meals = f_atol(av[5]);
	else
		ms->nb_meals = INT_MAX;
	if (ms->nb_philos < 1 || ms->tt_die < 0 || ms->tt_eat < 0 ||
		ms->tt_sleep < 0 || ms->nb_meals < 0)
		return (-1);
	return (0);
}
int	f_get_time(void)
{
	static struct timeval	start = {-1, -1};
	struct timeval			now;

	if (start.tv_sec == -1 && start.tv_usec == -1)
		gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 + now.tv_usec) - (start.tv_sec * 1000
			+ start.tv_usec));
}
