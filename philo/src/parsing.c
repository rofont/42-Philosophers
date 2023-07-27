/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:03:18 by romain            #+#    #+#             */
/*   Updated: 2023/07/25 21:13:10 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	f_check_digit(char *txt)
{
	int	i;

	if (!txt)
		return (-1);
	i = 0;
	while (txt[i])
	{
		if (!(txt[i] >= '0' && txt[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	f_atoi(char *txt)
{
	long	nb;
	int		i;

	if (!txt)
		return (-1);
	i = 0;
	nb = 0;
	while (txt[i])
		nb = (nb * 10) + (txt[i++] - 48);
	if (nb > 2147483647)
		exit(EXIT_FAILURE);
	return (nb);
}

int	f_parsing(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		f_all_clean(NULL, "error numbers arguments");
	while (av[i])
	{
		if (f_check_digit(av[i]) == -1 || f_atoi(av[i]) <= 0)
			f_all_clean(NULL, "error arguments");
		i++;
	}
	return (0);
}
