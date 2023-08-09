/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:46:05 by romain            #+#    #+#             */
/*   Updated: 2023/08/08 21:00:05 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// COLOR-----------------------------------------------------------------------

# define BCK "\x1B[30m"
# define RED "\x1B[31m"
# define GRE "\x1B[32m"
# define YEL "\x1B[33m"
# define BLE "\x1B[34m"
# define MAG "\x1B[35m"
# define CYA "\x1B[36m"
# define WHT "\x1B[37m"

// STRUCTURE-------------------------------------------------------------------

# define DEBUG 1
# define ERROR_ARG "🚨 : bad arguments was passed"
# define FORK "taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

typedef struct s_meta
{
	int	nb_philos;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	nb_meals;
}		t_meta;

typedef struct s_philo
{
	int id;
	pthread_t phil;
	t_meta *ms;
}	t_philo;

// PARSING---------------------------------------------------------------------

void	f_putstr_fd(char *txt, int fd);
int		f_atol(char *str);
int		f_is_digit(char *str);
int		f_parsing(char **av);

// INIT------------------------------------------------------------------------

int		f_init_meta(t_meta *ms, int ac, char **av);
int		f_get_time(void);

// ROUTINE---------------------------------------------------------------------

void *f_routine(void *data);

#endif