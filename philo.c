

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_t	thread;
	t_philo	*philo;

	check_args(ac, av);
	if(!(philo = malloc(ft_atoi(av[1]) * sizeof(t_philo))))
		return((write(2,"allocation failed!!!!!!",23)),1);
	if(!((*philo).data = malloc(sizeof(t_data))))
		return((write(2,"allocation failed!!!!!!",23)),1);
	parce_data(philo,ac,av);
    printf("%d\n%d\n%d\n%d\n%d",philo->data->nbr_philo,philo->data->time_to_die,philo->data->time_to_eat,philo->data->time_to_sleep,philo->data->nb_eat);
}