
#include "../include/philo.h"

void	f_print_meta(t_meta *ms)
{
	if (DEBUG == 1)
	{
		printf("nb_philo =%d=\n", ms->nb_philo);
		printf("tt_eat =%d=\n", ms->tt_eat);
		printf("tt_sleep =%d=\n", ms->tt_sleep);
		printf("tt_think =%d=\n", ms->tt_think);
		printf("nb_multi_eat =%d=\n", ms->nb_multi_eat);
	}
}
