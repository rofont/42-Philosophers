/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:04:42 by rofontai          #+#    #+#             */
/*   Updated: 2023/08/04 21:30:09 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_meta *ms;
	int i = 0;
	if ((ac == 5 || ac == 6) && (f_parsing(av) != -1))
	{
		if (f_init_meta(ms, ac, av) == -1)
			return (printf("%s\n", ERROR_ARG));
		if (f_init_philo(ms) == -1)
			return (printf("%s\n", "ERROR MALLOC"));



	}
	else
		return (printf("%s\n", ERROR_ARG));
	return (0);
}
