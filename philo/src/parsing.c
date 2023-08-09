/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:06:33 by romain            #+#    #+#             */
/*   Updated: 2023/08/08 20:08:40 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	f_putstr_fd(char *txt, int fd)
{
	int	i;

	i = 0;
	while (txt[i])
		write(fd, &txt[i++], 1);
	write(fd, "\n", 1);
}

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
