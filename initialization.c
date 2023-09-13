/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:27:10 by sozbayra          #+#    #+#             */
/*   Updated: 2023/09/13 20:25:03 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_initialize(t_philo *philos, t_program *program,
		pthread_mutex_t **forks, char **av)
{
	int	i;

    
	pthread_mutex_init(&program->write_lock, NULL);
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		pthread_mutex_init(&(*forks)[i], NULL);
		i++;
	}
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].philo_id = i + 1;
		philos[i].number_of_philos = ft_atoi(av[1]);
		philos[i].eat_time = ft_atoi(av[3]);
		philos[i].sleep_time = ft_atoi(av[4]);
		philos[i].write_lock = &program->write_lock;
		philos[i].r_fork = &(*forks)[i];
		if (i == 0)
			philos[i].l_fork = &(*forks)[philos[i].number_of_philos -1];
		else
			philos[i].l_fork = &(*forks)[i - 1];
		i++;
	}
}
