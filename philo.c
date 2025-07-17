/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:09:47 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/17 09:20:17 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitoring(t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->data->nb_philo)
		{
			pthread_mutex_lock(philo->data->mutex1);
			if (ft_get_time() - philo[i].last_eat > philo[i].data->time_to_die)
			{
				ft_print_dead(&philo[i]);
				philo->data->is_dead = 1;
				pthread_mutex_unlock(philo->data->mutex1);
				return ;
			}
			pthread_mutex_unlock(philo->data->mutex1);
			i++;
		}
		if (count_full_philosophers(philo) == philo->data->nb_philo)
			return (pthread_mutex_unlock(philo->data->mutex1), (void)0);
	}
}

int	ft_init_mutexes(t_philo *philo)
{
	int	i;

	philo->data->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo->data->print)
		return (1);
	pthread_mutex_init(philo->data->print, NULL);
	philo->data->mutex1 = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!philo->data->mutex1)
		return (1);
	pthread_mutex_init(philo->data->mutex1, NULL);
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo->data->nb_philo);
	if (!philo->forks)
		return (1);
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if ((ac != 5 && ac != 6) || ft_check_validity(ac, av) == true)
		return (ft_error("Wrong number of arguments or invalid arguments"));
	if (ft_atoi(av[1]) < 1 || ft_check_validity(ac, av) == true)
		return (0);
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (ft_error("Malloc failed"));
	philo->data = malloc(sizeof(t_data));
	if (!philo->data)
		return (ft_error("Malloc failed"));
	if (ft_fill_data(philo, ac, av) == 1)
		return (ft_error("Invalid arguments or malloc failed"));
	if (ft_init_mutexes(philo) == 1)
		return (ft_error("Mutex init failed"));
	ft_philo_construction(philo);
	ft_monitoring(philo);
	pthread_mutex_lock(philo->data->mutex1);
	if (philo->is_dead == 1 || philo->is_full == 1)
	{
		pthread_mutex_unlock(philo->data->mutex1);
		return (ft_free_all(philo),1);
	}
	return (0);

}