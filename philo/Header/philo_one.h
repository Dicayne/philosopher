/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:44:35 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/07 16:08:04 by vmoreau          ###   ########.fr       */
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
	int				ntpe_tot;			//NUMBER TIME PHILO EAT TOTAL
}				t_arg;

struct			s_data;
typedef struct	s_philo
{
	int				id;
	t_arg			arg;
	int				ntpe;				//NUMBER TIME PHILO EAT
	unsigned int	time_without_eat;
	pthread_t 		threads;
	pthread_mutex_t	fork;
	struct s_data	*data;
}				t_philo;

typedef struct	s_data
{
	int				nb_philo;
	bool			is_philo_dead;
	t_arg			arg;
	t_philo			*philos;
}				t_data;

// PHILO
void*			start_philo(void* thread);

// INIT
bool			init(t_data *data, char **av, int ac);
bool			init_thread(t_data *data);

// TIME
unsigned int 	get_time(bool start, unsigned int time_start);

// UTILS
bool			isnum(char *str);
int				ft_atoi(const char *str);
void			find_id_fork(t_philo *philo, int *id_left);

// EXIT_ERR
void			exit_err(int status, t_data *data);

// CHECK_ARGS
bool			check_args(char **av);
#endif
