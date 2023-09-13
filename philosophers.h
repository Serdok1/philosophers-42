/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:46:29 by sozbayra          #+#    #+#             */
/*   Updated: 2023/09/13 20:22:14 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_42/libft.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define PHILO_MAX 300

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	int				philo_id;
	int				eat_time;
	int				sleep_time;
	int				time_to_die;
	int				number_of_philos;
}					t_philo;

typedef struct s_program
{
	pthread_mutex_t	write_lock;
	t_philo			*philosophers;
}					t_program;

void				*ft_routine(void *philos);
int					ft_create_threads(t_philo *philos, t_program *program);
void				ft_initialize(t_philo *philos, t_program *program, pthread_mutex_t **forks, char **av);
void				ft_print_message(char *str, t_philo *philos);