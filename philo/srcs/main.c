/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:38:08 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/15 17:14:39 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

bool		have_eaten_enough(int ntpe_tot, int ntpe)
{
	if (ntpe_tot == -1)
		return (true);
	if (ntpe < ntpe_tot)
		return (true);
	else
		return (false);
}

void*		test(void *test)
{
	t_philo *philo;
	philo = (t_philo *)test;

	while (!philo->data->is_philo_dead &&
			have_eaten_enough(philo->arg.ntpe_tot, philo->ntpe))
	{
		philo->time_without_eat = get_time(false, philo->reset);
		if ((int)philo->time_without_eat >= philo->arg.time_die)
		{
			// printf("%d ptwe = %d\n", philo->id, philo->time_without_eat);
			display_status(philo, "DIE");
			pthread_mutex_unlock(&philo->fork);
			break;
		}
		usleep(500);
	}
	return (NULL);
}

void*		start_philo(void* thread)
{
	t_philo		*philo;
	pthread_t	cd;

	philo = (t_philo *)thread;
	philo->reset = get_time(true, philo->reset);
	pthread_create(&cd, NULL, &test, philo);
	while (!philo->data->is_philo_dead &&
			have_eaten_enough(philo->arg.ntpe_tot, philo->ntpe))
	{
		action_eat(philo);
		action_sleep(philo);
		display_status(philo, "THINK");
	}
	if (philo->arg.ntpe_tot != -1)
		printf("philo[%d] have eaten %d time\n", philo->id, philo->ntpe);
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
	if (!init_thread(&data))
		exit_err(4, &data);
	return (0);
}
