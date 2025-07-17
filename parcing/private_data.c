/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:09:14 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/17 09:25:13 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include "../philo.h"

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		ft_usleep(60);
	while (1)
	{
		pthread_mutex_lock(philo->data->mutex1);
		if (philo->data->nb_must_eat != -1
			&& philo->nb_eat >= philo->data->nb_must_eat)
			philo->is_full = 1;
		pthread_mutex_unlock(philo->data->mutex1);
		pthread_mutex_lock(philo->data->mutex1);
		if (philo->is_full == 1 || philo->is_over == 1)
		{
			pthread_mutex_unlock(philo->data->mutex1);
			break ;
		}
		pthread_mutex_unlock(philo->data->mutex1);
		ft_print(philo, "is thinking");
		ft_eat(philo);
		ft_print(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
	}
	return (NULL);
}

void	ft_philo_construction(t_philo *philo)
{
	int	i;

	
	i = 0;
	while (i < philo->data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].is_full = 0;
		philo[i].last_eat = ft_get_time();
		philo[i].nb_eat = 0;
		philo[i].data = philo->data;
		philo[i].forks = philo->forks;
		philo[i].left_fork = &philo->forks[i];
		philo[i].r_fork = &philo->forks[(i + 1) % philo->data->nb_philo];
		pthread_create(&philo[i].philo, NULL, routine, &philo[i]);
		i++;
	}
}