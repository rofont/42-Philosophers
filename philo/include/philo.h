/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:46:05 by romain            #+#    #+#             */
/*   Updated: 2023/08/04 21:24:32 by romain           ###   ########.fr       */
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

typedef struct s_meta	t_meta;
typedef struct s_philo
{
	int					id;
	int					status;
	int					nb_meal;
	time_t				last_meal;
	pthread_t			ph;
	t_meta				*ms;

}						t_philo;

typedef struct s_meta
{
	time_t				nb_philo;
	time_t				tt_die;
	time_t				tt_eat;
	time_t				tt_sleep;
	int					nb_meals;
	time_t				start;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
}						t_meta;

// PARSING---------------------------------------------------------------------

int						f_atol(char *str);
int						f_is_digit(char *str);
int						f_parsing(char **av);

// INIT------------------------------------------------------------------------

int						f_init_meta(t_meta *ms, int ac, char **av);
int						f_init_philo(t_meta *ms);

// A_SUPP----------------------------------------------------------------------

void					f_print_ms(t_meta *ms);

// UTILS-----------------------------------------------------------------------

time_t					f_get_time(void);

// ROUTINE---------------------------------------------------------------------

void *f_routine(void *arg);

#endif