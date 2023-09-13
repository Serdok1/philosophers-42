#include "philosophers.h"

int     ft_create_threads(t_philo *philos)
{
    int i = 0;

    while(i < philos[0].number_of_philos)
    {
        pthread_create(philos[i].thread, NULL, &ft_routine, &philos[i]);
        i++;
    }
    
    i = 0;
    while(i < philos[0].number_of_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}