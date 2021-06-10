/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:38:08 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/08 09:18:34 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
void	trytakefork(pthread_mutex_t *fork_l, pthread_mutex_t *fork_r, int l, int r)
{
	if (pthread_mutex_lock(fork_l) != 0)
		printf("%d Utiliser\n", l);
	if (pthread_mutex_lock(fork_r) != 0)
		printf("%d Utiliser\n", r);
	printf("[%d] take fork %d & %d\n", r, l, r);
}

void		releasefork(pthread_mutex_t *fork_l, pthread_mutex_t *fork_r, int l, int r)
{
	pthread_mutex_unlock(fork_l);
	pthread_mutex_unlock(fork_r);
	printf("[%d] release fork %d & %d\n", r, l, r);
}

void		test(t_philo *philo)
{
	int id_left;

	find_id_fork(philo, &id_left);
	trytakefork(&philo->data->philos[id_left - 1].fork, &philo->fork, id_left, philo->id);
	usleep(philo->arg.time_eat * 1000);
	releasefork(&philo->data->philos[id_left - 1].fork, &philo->fork, id_left, philo->id);
}

void*		start_philo(void* thread)
{
	t_philo *philo;
	unsigned int reset;

	philo = (t_philo *)thread;
	reset = philo->time_without_eat;
	while (philo->data->is_philo_dead == false)
	{
		philo->time_without_eat = get_time(false, reset);
		if ((int)philo->time_without_eat >= philo->arg.time_die)
		{
			printf("[%d]\t%d :Is Dead!\n", philo->id, get_time(false, philo->arg.time_start));
			philo->data->is_philo_dead = true;
			break;
		}
		printf("[%d]\t%d		test = %d\n", philo->id, get_time(false, philo->arg.time_start), philo->data->nb_philo);
		test(philo);
		usleep(500 * 1000);
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	t_data data;

	if (ac < 5 || ac > 6)
		exit_err(1, &data);
	if (!check_args(++av))
		exit_err(2, &data);
	if (!init(&data, av, ac))
		exit_err(3, &data);
	if (data.nb_philo < 2)
		exit_err(4, &data);
	if (!init_thread(&data))
		exit_err(5, &data);
	return (0);
}
