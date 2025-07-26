/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:49:46 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/25 11:01:42 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->data->shared_mut);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(philo->data->shared_mut);
		return ;
	}
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(philo->data->print_mut);
		printf("%ld %d %s\n", ft_get_time() - philo->data->start_time,
			philo->id, str);
		pthread_mutex_unlock(philo->data->print_mut);
	}
	pthread_mutex_unlock(philo->data->shared_mut);
}

void	print_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_nbr)
	{
		if (philo[i].is_full == 1)
			return ;
		i++;
	}
	pthread_mutex_lock(philo->data->print_mut);
	printf("%ld %d died\n", ft_get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(philo->data->print_mut);
}