/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:49:46 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/17 09:16:06 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->mutex1);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(philo->data->mutex1);
		return ;
	}
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(philo->data->print);
		printf("%ld %d %s\n", ft_get_time() - philo->data->start_time,
			philo->id, str);
		pthread_mutex_unlock(philo->data->print);
	}
	pthread_mutex_unlock(philo->data->mutex1);
}

void	ft_print_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		if (philo[i].is_full == 1)
			return ;
		i++;
	}
	pthread_mutex_lock(philo->data->print);
	printf("%ld %d died\n", ft_get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(philo->data->print);
}