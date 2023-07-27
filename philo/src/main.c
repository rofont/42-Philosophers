/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:04:42 by rofontai          #+#    #+#             */
/*   Updated: 2023/07/25 21:11:53 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_meta	*ms;

	f_parsing(ac, av);
	ms = f_init_meta(av);
	f_print_meta(ms); // TODO supprimer
	return (0);
}
