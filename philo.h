

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_eat;
}					t_data;


// parcing
void	check_args(int ac, char **av);


//utils
int	ft_atoi(const char *str);
int ft_strlen(char *str);

#endif
