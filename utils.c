#include "philosophers.h"

void    ft_print_message(char *str, t_philo *philos)
{
    pthread_mutex_lock(philos->write_lock);
    printf("%d. philosopher is %s...\n", philos->philo_id, str);
    pthread_mutex_unlock(philos->write_lock);
}