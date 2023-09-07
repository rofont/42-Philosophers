/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:32:08 by romain            #+#    #+#             */
/*   Updated: 2023/09/07 14:26:39 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int ac, char **av)
{
	t_data ms;
	t_philo ph[250];

	if(f_parsing(ac, av))
	{
		f_init_data(ac, av, &ms);
		f_init_philo(&ms, ph);
		if (ms.nb_philo > 1)
			f_progress(&ms, ph);
	}
	return (0);
}
