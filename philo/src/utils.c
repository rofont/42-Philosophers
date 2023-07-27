/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:24:54 by romain            #+#    #+#             */
/*   Updated: 2023/07/25 21:13:30 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_meta	*f_init_meta(char **av)
{
	static t_meta	*new;

	if (!new)
	{
		new = f_calloc(sizeof(t_meta), 1);
		if (!new)
			return (0);
		new->nb_philo = f_atoi(av[1]);
		new->tt_eat = f_atoi(av[2]);
		new->tt_sleep = f_atoi(av[3]);
		new->tt_think = f_atoi(av[4]);
		new->nb_multi_eat = f_atoi(av[5]);
	}
	return (new);
}

void	f_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp;

	if (!s)
		return ;
	i = 0;
	temp = (char *)s;
	while (i < n)
		temp[i++] = '\0';
}

void	*f_calloc(size_t size, size_t count)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	f_bzero(ptr, (count * size));
	return (ptr);
}

void	f_all_clean(t_meta *ms, char *txt)
{
	if (ms)
		free(ms);
	if (txt)
	{
		printf("🚨 %s\n", txt);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
