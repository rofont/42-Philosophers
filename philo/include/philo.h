/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:46:05 by romain            #+#    #+#             */
/*   Updated: 2023/07/25 21:12:45 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
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

typedef struct s_meta
{
	int	nb_philo;
	int	tt_eat;
	int	tt_sleep;
	int	tt_think;
	int	nb_multi_eat;
}		t_meta;

// PARSING---------------------------------------------------------------------

int		f_check_digit(char *txt);
int		f_atoi(char *txt);
int		f_parsing(int ac, char **av);

// UTILS-----------------------------------------------------------------------

void	f_bzero(void *s, size_t n);
void	*f_calloc(size_t size, size_t count);
void	f_all_clean(t_meta *ms, char *txt);
t_meta	*f_init_meta(char **av);

// A_SUPP----------------------------------------------------------------------

void	f_print_meta(t_meta *ms);

#endif