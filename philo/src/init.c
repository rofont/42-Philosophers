/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:37:53 by romain            #+#    #+#             */
/*   Updated: 2023/08/22 20:08:32 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void f_init_data(int ac, char **av, t_data *ms)
{
	ms->nb_philo = f_atol(av[1]);
	ms->tt_die = f_atol(av[2]);
	ms->tt_eat = f_atol(av[3]);
	ms->tt_sleep = f_atol(av[4]);
	if (ac == 6)
	ms->nb_meals = f_atol(av[5]);
	else
		ms->nb_meals = INT_MAX;
	if (ms->nb_philo < 1 || ms->tt_die < 1 || ms->tt_eat < 1 ||
		ms->tt_sleep < 1 || ms->nb_meals < 0)
	{
		f_putstr_fd(ERROR_ARG, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}