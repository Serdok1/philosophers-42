#include "philosophers.h"
void    ft_eat(t_philo *philos)
{
    pthread_mutex_lock(philos->r_fork);
    ft_print_message("take the right fork", philos);
    pthread_mutex_lock(philos->l_fork);
    ft_print_message("take the left fork", philos);
    ft_print_message("eating", philos);
    usleep(philos->eat_time*1000);
}

void    ft_sleep(t_philo *philos)
{
    ft_print_message("sleeping", philos);
    pthread_mutex_unlock(philos->r_fork);
    pthread_mutex_unlock(philos->l_fork);
    usleep(philos->sleep_time*1000);
}

void    ft_think(t_philo *philos)
{
    ft_print_message("thinking", philos);
}

void *ft_routine(void *philos)
{
    t_philo *philosopher;

    philosopher = (t_philo *)philos;

    ft_eat(philosopher);
    ft_sleep(philosopher);
    ft_think(philosopher);
    
    return(0);
}