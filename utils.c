

#include "philo.h"

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
