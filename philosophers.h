/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbayra <sozbayra@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:46:29 by sozbayra          #+#    #+#             */
/*   Updated: 2023/09/12 22:56:19 by sozbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "libft_42/libft.h"
#include "ft_printf/ft_printf.h"

# define PHILO_MAX 300

typedef struct s_philo
{
    pthread_t       thread;
    pthread_mutex_t mutex;
    pthread_mutex_t r_fork;
    pthread_mutex_t l_fork;
    int             philo_id;
    int             eat_time;
    int             sleep_time;
    int             number_of_philos;
}              t_philo;

void*   ft_routine(t_philo *philos);
int     ft_create_threads(t_philo *philos);