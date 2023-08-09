/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:32:08 by romain            #+#    #+#             */
/*   Updated: 2023/08/08 20:41:52 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_print_ms(t_meta *ms) // TODO supprimer
{
	if (DEBUG == 1)
	{
		printf("nb_philo =%d=\n", ms->nb_philos);
		printf("tt_die =%d=\n", ms->tt_die);
		printf("tt_eat =%d=\n", ms->tt_eat);
		printf("tt_sleep =%d=\n", ms->tt_sleep);
		printf("nb_meals =%d=\n", ms->nb_meals);
	}
}

int	main(int ac, char **av)
{
	t_meta	ms;

	if (!((ac == 5 || ac == 6) && (f_parsing(av) != -1)))
	{
		f_putstr_fd(ERROR_ARG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (f_init_meta(&ms, ac, av) == -1)
	{
		f_putstr_fd(ERROR_ARG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}

	int i = 0;
	t_philo ph[ms.nb_philos];

	while (i < ms.nb_philos)
	{
		ph[i].id = i + 1;
		ph[i].ms = &ms;
		i++;
	}
	i = 0;
	while (i < ms.nb_philos)
	{
		pthread_create(&ph[i].phil, NULL, &f_routine, &ph[i]);
		i++;
	}
	i = 0;
	while (i < ms.nb_philos)
	{
		pthread_join(ph[i].phil, NULL);
		i++;
	}
	// f_print_ms(&ms); // TODO supprimer
	return (0);
}
