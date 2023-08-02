/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:22:29 by romain            #+#    #+#             */
/*   Updated: 2023/08/01 20:48:17 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	f_init_meta(t_meta *ms, int ac, char **av)
{
	ms->nb_philo = f_atol(av[1]);
	ms->tt_eat = f_atol(av[2]);
	ms->tt_die = f_atol(av[3]);
	ms->tt_sleep = f_atol(av[4]);
	if (ms->nb_philo < 1 || ms->nb_philo > 200 ||
		ms->tt_eat < 0 || ms->tt_die < 0 || ms->tt_sleep < 0)
		return (-1);
	if (ac == 6)
		ms->nb_meals = f_atol(av[5]);
	else
		ms->nb_meals = INT_MAX;
	return (0);
}
