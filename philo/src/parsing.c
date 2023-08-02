/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:03:18 by romain            #+#    #+#             */
/*   Updated: 2023/08/01 15:26:31 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	f_atol(char *str)
{
	long	nb;
	int		i;

	nb = 0;
	i = 0;
	if (!str)
		return (-1);
	while (str[i])
		nb = (nb * 10) + (str[i++] - 48);
	if (nb > INT_MAX)
		return (-1);
	return (nb);
}

int	f_is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (0);
}

int	f_parsing(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (f_is_digit(av[i]) == -1 || f_atol(av[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
