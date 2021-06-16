/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:38:08 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/16 22:07:51 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	have_eaten_enough(int ntpe_tot, int ntpe)
{
	if (ntpe_tot == -1)
		return (true);
	if (ntpe < ntpe_tot)
		return (true);
	else
		return (false);
}

void	*check_death(void *test)
{
	t_philo	*philo;

	philo = (t_philo *)test;
	while (!philo->data->is_philo_dead && \
			have_eaten_enough(philo->arg.ntpe_tot, philo->ntpe))
	{
		philo->time_without_eat = get_time(false, philo->reset);
		if ((int)philo->time_without_eat >= philo->arg.time_die)
		{
			display_status(philo, "DIE");
			pthread_mutex_unlock(&philo->fork);
			break ;
		}
		usleep(500);
	}
	return (NULL);
}

void	*start_philo(void *thread)
{
	t_philo		*philo;
	pthread_t	cd;

	philo = (t_philo *)thread;
	philo->reset = get_time(true, philo->reset);
	pthread_create(&cd, NULL, &check_death, philo);
	pthread_detach(cd);
	while (!philo->data->is_philo_dead && \
			have_eaten_enough(philo->arg.ntpe_tot, philo->ntpe))
	{
		action_eat(philo);
		action_sleep(philo);
		display_status(philo, "THINK");
	}
	if (philo->arg.ntpe_tot != -1)
		printf("%sPhilo[%d] have eaten %d time%s\n"\
				, PURPLE, philo->id, philo->ntpe, NC);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;
	int		ret;

	ret = 0;
	if (ac < 5 || ac > 6)
		ret = exit_err(1, &data);
	else if (!check_args(++av))
		ret = exit_err(2, &data);
	else if (!init(&data, av, ac))
		ret = exit_err(3, &data);
	else if (!init_thread(&data))
		ret = exit_err(4, &data);
	return (ret);
}
