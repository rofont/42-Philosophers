/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofontai <rofontai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:32:08 by romain            #+#    #+#             */
/*   Updated: 2023/09/20 09:38:51 by rofontai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

time_t	get_time(void)
{
	static struct timeval	start = {-1, -1};
	struct timeval			now;

	if (start.tv_sec == -1 && start.tv_usec == -1)
		gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 - start.tv_sec * 1000) + \
	(now.tv_usec / 1000 - start.tv_usec / 1000));
}

void	f_init_data(int ac, char **av, t_data *ms)
{
	ms->nb_philo = f_atol(av[1]);
	ms->tt_die = f_atol(av[2]);
	ms->tt_eat = f_atol(av[3]);
	ms->tt_sleep = f_atol(av[4]);
	if (ac == 6)
		ms->nb_meals = f_atol(av[5]);
	else
		ms->nb_meals = INT_MAX;
	if (ms->nb_philo < 1 || ms->tt_die < 1 || ms->tt_eat < 1
		|| ms->tt_sleep < 1 || ms->nb_meals < 0)
	{
		f_putstr_fd(ERROR_ARG, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
	pthread_mutex_init(&ms->msg, NULL);
	pthread_mutex_init(&ms->var, NULL);
	pthread_mutex_init(&ms->key, NULL);
	ms->dead = 0;
}

void	f_init_philo(t_data *ms, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ms->nb_philo)
	{
		ph[i].id = i + 1;
		ph[i].full = 0;
		ph[i].last_meal = 0;
		pthread_mutex_init(&ph[i].l_fork, NULL);
		if (i > 0)
			ph[i].r_fork = &ph[i - 1].l_fork;
		ph[i].meals = 0;
		ph[i].info = ms;
	}
	ph[0].r_fork = NULL;
	if (ms->nb_philo > 1)
		ph[0].r_fork = &ph[ms->nb_philo - 1].l_fork;
}

void	*f_routine_alone(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	pthread_mutex_lock(&ph->l_fork);
	f_message(FORK, ph, ph->info);
	f_wait_while(ph->info->tt_die);
	pthread_mutex_unlock(&ph->l_fork);
	return (arg);
}

int	main(int ac, char **av)
{
	t_data	ms;
	t_philo	ph[250];

	if (f_parsing(ac, av))
	{
		f_init_data(ac, av, &ms);
		f_init_philo(&ms, ph);
		f_progress(&ms, ph);
	}
	return (0);
}
