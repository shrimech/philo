/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:10:07 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/25 11:02:02 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(philo->data->shared_mut);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(philo->data->shared_mut);
	pthread_mutex_lock(philo->data->shared_mut);
	philo->nb_eat++;
	pthread_mutex_unlock(philo->data->shared_mut);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->r_fork);
}


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}



int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_full_philosophers(t_philo *philo)
{
	int	i;
	int	eat_nb;

	i = 0;
	eat_nb = 0;
	while (i < philo->data->philo_nbr)
	{
		pthread_mutex_lock(philo->data->shared_mut);
		if (philo[i].is_full == 1)
			eat_nb++;
		i++;
		pthread_mutex_unlock(philo->data->shared_mut);
	}
	return (eat_nb);
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
