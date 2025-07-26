/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:09:21 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/25 11:01:10 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_validity(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0)
			return (1);
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_data(t_philo *philo, int ac, char **av)
{
	if (check_validity(ac, av))
		return (1);
	philo->data->philo_nbr = ft_atoi(av[1]);
	philo->data->time_to_die = ft_atoi(av[2]);
	philo->data->time_to_eat = ft_atoi(av[3]);
	philo->data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->data->nb_must_eat = ft_atoi(av[5]);
	else
		philo->data->nb_must_eat = -1;
	philo->data->is_dead = 0;
	philo->data->start_time = ft_get_time();
	return (0);
}
