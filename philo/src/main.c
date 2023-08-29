/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:32:08 by romain            #+#    #+#             */
/*   Updated: 2023/08/28 16:40:21 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int ac, char **av)
{
	t_data ms;
	t_philo ph[1000];

	if(f_parsing(ac, av))
	{
		f_init_data(ac, av, &ms);
		f_init_philo(&ms, ph);
		f_print_ms(&ms);
		f_progress(&ms, ph);
		f_print_ms(&ms);
	}
	return (0);
}
