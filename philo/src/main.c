/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:32:08 by romain            #+#    #+#             */
/*   Updated: 2023/09/19 21:00:15 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_data	ms;
	t_philo	ph[250];

	if (f_parsing(ac, av))
	{
		f_init_data(ac, av, &ms);
		f_init_philo(&ms, ph);
		if (ms.nb_philo > 1)
			f_progress(&ms, ph);
	}
	return (0);
}
