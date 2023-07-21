/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:04:42 by rofontai          #+#    #+#             */
/*   Updated: 2023/07/20 21:47:42 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main (int ac, char **av)
{
	(void)av;

	if (ac < 5 || ac > 6)
		exit (EXIT_FAILURE);
	printf ("salut la compagnie\n");
	return (0);
}