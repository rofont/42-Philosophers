/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:22:29 by romain            #+#    #+#             */
/*   Updated: 2023/08/04 21:29:11 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	f_init_meta(t_meta *ms, int ac, char **av)
{
	ms->nb_philo = f_atol(av[1]);
	ms->tt_eat = f_atol(av[2]);
	ms->tt_die = f_atol(av[3]);
	ms->tt_sleep = f_atol(av[4]);
	if (ms->nb_philo < 1 || ms->tt_eat < 0 || ms->tt_die < 0
		|| ms->tt_sleep < 0)
		return (-1);
	if (ac == 6)
		ms->nb_meals = f_atol(av[5]);
	else
		ms->nb_meals = INT_MAX;
	ms->forks = malloc(sizeof(pthread_mutex_t) * (ms->nb_philo +1));
	if (!ms->forks)
		return (-1);
	return (0);
}

int	f_init_philo(t_meta *ms)
{
	int	i;

	i = 0;
	ms->philos = malloc(sizeof(t_philo) * (ms->nb_philo + 1));
	if (!ms->philos)
		return (-2);
	pthread_mutex_init(&ms->lock, NULL);
	while (i < ms->nb_philo)
	{
		ms->philos[i].ms = ms;
		ms->philos[i].id = i + 1;
		ms->philos[i].nb_meal = 0;
		ms->philos[i].status = 0;
		pthread_mutex_init(&ms->forks[i], NULL);
		pthread_create(&ms->philos[i].ph, NULL, &f_routine,
			(void *)&ms->philos[i]);
	}
	return (0);
}
