/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 08:38:36 by shrimech          #+#    #+#             */
/*   Updated: 2025/07/17 09:21:14 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
#include <bits/pthreadtypes.h>
# include <semaphore.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef pthread_mutex_t l9fel;

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	long			start_time;
	int				is_dead;
	l9fel			*mutex1;
	l9fel			*print;
	
}					t_data;

typedef struct s_philo
{
	int				id;

	int				is_dead;
	int				is_full;
	int				is_over;
	int				is_started;
	long			last_eat;
	int				nb_eat;

	pthread_t		philo;
	t_data			*data;

	l9fel			*forks;
	l9fel			*left_fork;
	l9fel			*r_fork;
}					t_philo;

int					ft_atoi(const char *str);
int					ft_error(char *str);
int					ft_check_validity(int ac, char **av);
int					ft_strlen(char *str);
int					count_full_philosophers(t_philo *philo);
void				ft_print(t_philo *philo, char *str);
void				ft_philo_construction(t_philo *philo);
void				ft_eat(t_philo *philo);
void				ft_free_all(t_philo *philo);
void				ft_print_dead(t_philo *philo);
int					ft_free(t_philo *philo);
int					ft_fill_data(t_philo *philo, int ac, char **av);
long				ft_get_time(void);
void				ft_usleep(long time);

#endif
