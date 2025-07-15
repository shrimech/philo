/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:10:07 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/15 15:22:20 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_strlen(char *str)
{
    int i = 0;

    while(str[i])
        i++;
    return(i);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
        if (num > 2147483647)
            return(num);
	}
	return (num);
}

void	ft_mutex_init(t_philo *philo)
{
	int	i;

	pthread_mutex_init(&philo->data->print, NULL);

	pthread_mutex_init(&philo->data->saving, NULL);
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo->data->nbr_philo);
	if (!philo->forks)
		exit (1);
	i = 0;
	while (i < philo->data->nbr_philo)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
}

int	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(long time)
{
	long	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
		usleep(500);
}

void	ft_print_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
		if (philo[i].full == 1)
			return ;
		i++;
	}
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d died\n", ft_get_time() - philo->data->starting, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}


int	count_full_philosophers(t_philo *philo)
{
	int	i;
	int	eat_nb;

	i = 0;
	eat_nb = 0;
	while (i < philo->data->nbr_philo)
	{
		pthread_mutex_lock(&philo->data->saving);
		if (philo[i].full == 1)
			eat_nb++;
		i++;
		pthread_mutex_unlock(&philo->data->saving);
	}
	return (eat_nb);
}

void	ft_free_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
		pthread_join(philo[i].thread, NULL);
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->data->print);
	pthread_mutex_destroy(&philo->data->saving);
	free(philo->forks);
	free(philo->data);
	free(philo);
}
