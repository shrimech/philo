


#include "philo.h"

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
		if (ft_atoi(av[i]) < 1 || ft_atoi(av[i]) > 2147483647)
            exit((write(2,"arguments should be beggest then 1  && less than int max",56),1));
        j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				exit((write(2,"arguments should contain just numbers",37),1));
			j++;
		}
		i++;
	}
}