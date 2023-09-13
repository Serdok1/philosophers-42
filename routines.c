#include "philosophers.h"
void    ft_eat(int philo_id, int eat_time)
{
    ft_printf("%d. philo is eating...", philo_id);
    usleep(eat_time);
}

void    ft_sleep(int philo_id, int sleep_time)
{
    ft_printf("%d. philo is sleeping...", philo_id);
    usleep(sleep_time);
}

void    ft_think(int philo_id)
{
    ft_printf("%d. philo is thinking...", philo_id);
}

void*   ft_routine(t_philo *philos)
{
    t_philo *philosopher;

    philosopher = (t_philo *)philos;
    ft_eat(philosopher->philo_id, philosopher->eat_time);
    ft_sleep(philosopher->philo_id, philosopher->sleep_time);
    ft_think(philosopher->philo_id);
    
    return(philos);
}