/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:28:58 by romain            #+#    #+#             */
/*   Updated: 2023/08/08 20:59:30 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *f_routine(void *data)
{
	t_philo *phil;
	phil = (t_philo *)data;

	usleep(50);
	while (f_get_time() < phil->ms->tt_die)
	{
		printf (" %d = alive id = %d\n", f_get_time(), phil->id);
		if (phil->id % 2 == 0)
			printf("ici\n");
	}
	return (data);
}