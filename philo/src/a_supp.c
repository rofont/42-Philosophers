/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_supp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:48:13 by romain            #+#    #+#             */
/*   Updated: 2023/09/06 13:01:12 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_print_ms(t_data *ms) // TODO supprimer
{
	if (DEBUG == 1)
	{
		printf("nb_philo =%d=\n", ms->nb_philo);
		printf("tt_die =%ld=\n", ms->tt_die);
		printf("tt_eat =%ld=\n", ms->tt_eat);
		printf("tt_sleep =%ld=\n", ms->tt_sleep);
		printf("nb_meals =%d=\n", ms->nb_meals);
		printf("dead =%d=\n", ms->dead);
	}
}
