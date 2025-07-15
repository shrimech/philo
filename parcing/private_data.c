/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:09:14 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/15 14:59:20 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include "../philo.h"


void	ft_start_simulation(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].full = 0;
		philo[i].last_eat = ft_get_time();
		philo[i].nb_eat = 0;
		philo[i].data = philo->data;
		philo[i].forks = philo->forks;
		philo[i].l_fork = philo->forks[i];
		philo[i].r_fork = philo->forks[(i + 1) % philo->data->nbr_philo];
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
}