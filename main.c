/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:46:26 by sozbayra          #+#    #+#             */
/*   Updated: 2023/09/13 20:25:30 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	*forks;

	forks = malloc(10000);
    program.philosophers = philos;
	if (ac == 4 || ac == 5)
	{
		ft_initialize(philos, &program, &forks, av);
		ft_create_threads(philos, &program);
	}
	else
	{
		printf("Please enter 4 or 5 args.");
	}
	return (0);
}
