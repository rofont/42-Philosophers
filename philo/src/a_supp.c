
#include "../include/philo.h"

void	f_print_ms(t_meta *ms)
{
	if (DEBUG == 1)
	{
		printf("nb_philo =%ld=\n", ms->nb_philo);
		printf("tt_die =%ld=\n", ms->tt_die);
		printf("tt_eat =%ld=\n", ms->tt_eat);
		printf("tt_sleep =%ld=\n", ms->tt_sleep);
		printf("nb_meals =%d=\n", ms->nb_meals);
	}
}