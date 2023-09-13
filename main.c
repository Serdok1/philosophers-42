/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:46:26 by sozbayra          #+#    #+#             */
/*   Updated: 2023/09/12 23:01:21 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_initialize(t_philo *philos, pthread_mutex_t *forks, char **av)
{
    int i;

    i = 0;

    while(i < av[1])
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }

    i = 0;

    while(i < av[1])
    {
        philos[i].philo_id = i + 1;
        philos[i].number_of_philos = av[1];
        philos[i].eat_time = av[3];
        philos[i].sleep_time = av[4];
        philos[i].r_fork = forks[i];
        if(i == 0)
            philos[i].l_fork = forks[philos[i].number_of_philos];
        else
            philos[i].l_fork = forks[i - 1];
        i++;
    }
}



int main(int ac, char **av)
{
    t_philo philos[PHILO_MAX];
    pthread_mutex_t forks[PHILO_MAX];

    ft_initialize(philos, forks, av);
    ft_create_threads(philos);
    return (0);
}