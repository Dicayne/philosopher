/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:44:35 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/03 21:36:59 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_ONE_H
# define PHILO_ONE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
// STRUCTURE
typedef struct	s_arg
{
	unsigned int	time_start;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				ntpe_tot;
}				t_arg;

typedef struct	s_philo
{
	int				id;
	t_arg			arg;
	int				ntpe;
	unsigned int	time_without_eat;
	pthread_t 		threads;
	pthread_mutex_t	fork;
}				t_philo;

typedef struct	s_data
{
	int				nb_philo;
	t_arg			arg;
	t_philo			*philos;
}				t_data;

// PHILO
void*			start_philo(void* thread);

// INIT
bool			init(t_data *data, char **av, int ac);
bool			init_thread(t_data *data);

// TIME
unsigned int get_time(bool start, unsigned int time_start);

// UTILS
bool			isnum(char *str);
int				ft_atoi(const char *str);

// EXIT_ERR
void			exit_err(int status, t_data *data);

// CHECK_ARGS
bool			check_args(char **av);
#endif
