/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:38:08 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/11 17:44:16 by vmoreau          ###   ########.fr       */
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

void*		start_philo(void* thread)
{
	t_philo *philo;
	unsigned int reset;

	philo = (t_philo *)thread;
	reset = philo->arg.time_start;
	while (!philo->data->is_philo_dead &&
			have_eaten_enough(philo->arg.ntpe_tot, philo->ntpe))
	{
		philo->time_without_eat = get_time(false, reset);
		if ((int)philo->time_without_eat >= philo->arg.time_die)
		{
			display_status(philo, "DIE");
			philo->data->is_philo_dead = true;
			break;
		}
		action_eat(philo, &reset);
		action_sleep(philo);
		display_status(philo, "THINK");
	}
	// printf("philo[%d] have eaten %d time\n", philo->id, philo->ntpe);
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
