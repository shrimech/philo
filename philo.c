/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:09:47 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/15 15:28:32 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitoring(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (i < philo->data->nbr_philo)
		{
			i++;
			pthread_mutex_lock(&philo->data->saving);
			if (ft_get_time() - philo[i].last_eat > philo[i].data->time_to_die)
			{
				ft_print_dead(&philo[i]);
				philo->data->is_dead = 1;
				pthread_mutex_unlock(&philo->data->saving);
				return ;
			}
			pthread_mutex_unlock(&philo->data->saving);
		}
		if (count_full_philosophers(philo) == philo->data->nbr_philo)
			return (pthread_mutex_unlock(&philo->data->saving), (void)0);
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	check_args(ac, av);
	if(!(philo = malloc(ft_atoi(av[1]) * sizeof(t_philo))))
		return((write(2,"allocation failed!!!!!!",23)),1);
	if(!(philo->data = malloc(sizeof(t_data))))
		return((write(2,"allocation failed!!!!!!",23)),1);
	parce_data(philo,ac,av);
	ft_mutex_init(philo);
	// printf("ffffffffffffffffffffffffff");
	(ft_start_simulation(philo), ft_monitoring(philo));
	pthread_mutex_lock(&philo->data->saving);
	if (philo->dead == 1 || philo->full == 1)
	{
		pthread_mutex_unlock(&philo->data->saving);
		return (ft_free_all(philo),1);
	}
}