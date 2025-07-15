

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>


typedef pthread_mutex_t t_mutex;

typedef struct s_data
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				nb_eat;
	long			starting;
	int				is_dead;
	t_mutex			print;
	t_mutex			saving;
}					t_data;


typedef struct s_philo
{
	t_data			*data;
	pthread_t		thread;
	t_mutex			*forks;
	t_mutex			l_fork;
	t_mutex			r_fork;
	int				id;
	int				full;
	int				dead;
	int				over;
	int				nb_eat;
	int				last_eat;				
}					t_philo;



// parcing
void	check_args(int ac, char **av);
void	parce_data(t_philo *philo, int ac, char **av);


//utils
int	ft_atoi(const char *str);
int ft_strlen(char *str);
void	ft_mutex_init(t_philo *philo);
int	ft_get_time(void);
void	ft_usleep(long time);
void	ft_print_dead(t_philo *philo);
int	count_full_philosophers(t_philo *philo);
void	ft_free_all(t_philo *philo);

//routine
void	ft_start_simulation(t_philo *philo);
void	*routine(void *p);



#endif
