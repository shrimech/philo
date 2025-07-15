/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 06:09:21 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/14 03:15:53 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../philo.h"

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
    if (ac != 5 && ac != 6)
		exit((write(2,"Wrong number of arguments",25),1));
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0)
			exit((write(2,"please don't let empty arguments",32),1));
        j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				exit((write(2,"arguments should contain just numbers",37),1));
			j++;
		}
		if (ft_atoi(av[i]) < 1 || ft_atoi(av[i]) > 2147483647)
			exit((write(2,"arguments should be beggest then 1  && less than int max",56),1));
		i++;
	}
}

void	parce_data(t_philo *philo, int ac, char **av)
{
	philo->data->nbr_philo = ft_atoi(av[1]);
	philo->data->time_to_die = ft_atoi(av[2]);
	philo->data->time_to_eat = ft_atoi(av[3]);
	philo->data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->data->must_eat = ft_atoi(av[5]);
	else
		philo->data->must_eat = -1;
	philo->data->starting = ft_get_time();
	philo->data->is_dead = 0;
}