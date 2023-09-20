/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:14:31 by romain            #+#    #+#             */
/*   Updated: 2023/09/19 20:56:27 by romain           ###   ########.fr       */
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

bool	f_is_digit(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (false);
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
	return (true);
}

bool	f_check(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!f_is_digit(av[i]) || f_atol(av[i]) == -1)
		{
			f_putstr_fd(ERROR_ARG, STDERR_FILENO);
			exit (EXIT_FAILURE);
		}
	}
	return (true);
}

bool	f_parsing(int ac, char **av)
{
	if ((ac == 5 || ac == 6) && f_check(av))
		return (true);
	f_putstr_fd(ERROR_NB_ARG, STDERR_FILENO);
	exit (EXIT_FAILURE);
}
