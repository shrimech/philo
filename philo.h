

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_eat;
	int				nb_eat;
}					t_data;


typedef struct s_philo
{
	int				id;
	t_data			*data;

}					t_philo;



// parcing
void	check_args(int ac, char **av);
void	parce_data(t_philo *philo, int ac, char **av);


//utils
int	ft_atoi(const char *str);
int ft_strlen(char *str);

#endif
