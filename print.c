/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:49:46 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/15 14:52:17 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->saving);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->saving);
		return ;
	}
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_lock(&philo->data->saving);
		printf("%ld %d %s\n", ft_get_time() - philo->data->starting,
			philo->id, str);
		pthread_mutex_unlock(&philo->data->print);
	}
	pthread_mutex_unlock(&philo->data->saving);
}