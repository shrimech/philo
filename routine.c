/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:41:39 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/15 14:56:57 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	ft_print(t_philo *philo, char *str)
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

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->r_fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	pthread_mutex_lock(&philo->data->saving);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&philo->data->saving);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_lock(&philo->data->saving);
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->data->saving);
}

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		ft_usleep(60);
	while (1)
	{
		pthread_mutex_lock(&philo->data->saving);
		if (philo->data->must_eat != -1
			&& philo->nb_eat >= philo->data->must_eat)
			philo->full = 1;
		pthread_mutex_unlock(&philo->data->saving);
		pthread_mutex_lock(&philo->data->saving);
		if (philo->full == 1 || philo->over == 1)
		{
			pthread_mutex_unlock(&philo->data->saving);
			break ;
		}
		pthread_mutex_unlock(&philo->data->saving);
		ft_print(philo, "is thinking");
		ft_eat(philo);
		ft_print(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
	}
	return (NULL);
}