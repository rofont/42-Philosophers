/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:46:05 by romain            #+#    #+#             */
/*   Updated: 2023/08/28 14:52:59 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
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

// MESSAGE---------------------------------------------------------------------
# define DEBUG 1
# define ERROR_ARG "\n🚨 : one or more arguments are not correct\n"
# define ERROR_NB_ARG "\n🚨 : require ./philo <nb_philo> <tt_die> <tt_eat> <tt_sleep> and/or <nb_meals>\n"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

// STRUCTURE-------------------------------------------------------------------

typedef struct s_data
{
	int				nb_philo;
	time_t			tt_die;
	time_t			tt_eat;
	time_t			tt_sleep;
	int				nb_meals;
	int				dead;
	int				full;
	pthread_mutex_t	msg;
	pthread_mutex_t	var;
}					t_data;

typedef struct s_philo
{
	int				id;
	bool			alive;
	int				meals;
	time_t			last_meal;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	t_data			*info;
}					t_philo;

// PARSING---------------------------------------------------------------------

void				f_putstr_fd(char *txt, int fd);
int					f_atol(char *str);
bool				f_is_digit(char *str);
bool				f_check(char **av);
bool				f_parsing(int ac, char **av);

// INIT------------------------------------------------------------------------

time_t				get_time(void);
void				f_init_data(int ac, char **av, t_data *ms);
void				f_init_philo(t_data *ms, t_philo *ph);

// ROUTINE--------------------------------------------------------------------

void				*f_routine(void *arg);
void				f_destroy(pthread_t *eater, t_philo *ph, t_data *ms);
void				f_make_philo(pthread_t *eater, t_philo *ph, t_data *ms);
void				f_progress(t_data *ms, t_philo *ph);

// UTILS-----------------------------------------------------------------------

void				f_message(char *txt, t_philo *ph, t_data *ms);

// A_SUPP----------------------------------------------------------------------

void				f_print_ms(t_data *ms);

#endif