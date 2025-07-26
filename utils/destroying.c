/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroying.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:47:25 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/25 11:01:23 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


void	ft_usleep(long time)
{
	long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(500);
}

int	ft_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

void	free_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nbr)
	{
		pthread_join(philo[i].philo, NULL);
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(philo->data->print_mut);
	pthread_mutex_destroy(philo->data->shared_mut);
	free(philo->data->shared_mut);
	free(philo->forks);
	free(philo->data->print_mut);
	free(philo->data);
	free(philo);
}