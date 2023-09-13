#include "philosophers.h"

int     ft_create_threads(t_philo *philos, t_program *program)
{
    int i = 0;

    while(i < philos[0].number_of_philos)
    {        
        pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]);
        i += 2;
    }
    usleep(philos[0].number_of_philos*40);

    i = 1;
    while(i < philos[0].number_of_philos)
    {        
        pthread_create(&philos[i].thread, NULL, ft_routine, &philos[i]);
        i += 2;
    }

    
    i = 0;
    while(i < philos[0].number_of_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }

    return (0);
}