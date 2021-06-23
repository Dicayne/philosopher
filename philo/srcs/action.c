/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:38:44 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/23 17:10:34 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	find_id_fork(t_philo *philo, int *id_left)
{
	if (philo->id == 1)
		*id_left = philo->data->philos[philo->data->nb_philo - 1].id;
	else
		*id_left = philo->id - 1;
}

void	t_fork(pthread_mutex_t *f_l, pthread_mutex_t *f_r, t_philo *philo)
{
	pthread_mutex_lock(f_l);
	display_status(philo, "FORK");
	pthread_mutex_lock(f_r);
	display_status(philo, "FORK");
}

void	r_fork(pthread_mutex_t *f_l, pthread_mutex_t *f_r)
{
	pthread_mutex_unlock(f_l);
	pthread_mutex_unlock(f_r);
}

void	action_eat(t_philo *philo)
{
	int	id_left;

	find_id_fork(philo, &id_left);
	t_fork(&philo->data->philos[id_left - 1].fork, &philo->fork, philo);
	pthread_mutex_lock(&philo->eat_or_die);
	display_status(philo, "EAT");
	philo->ntpe++;
	philo->reset = get_time(true, philo->reset);
	philo->time_without_eat = get_time(false, philo->reset);
	ft_wait(philo->arg.time_eat, philo->data->is_philo_dead);
	r_fork(&philo->data->philos[id_left - 1].fork, &philo->fork);
	pthread_mutex_unlock(&philo->eat_or_die);
}

void	action_sleep(t_philo *philo)
{
	display_status(philo, "SLEEP");
	ft_wait(philo->arg.time_sleep, philo->data->is_philo_dead);
}
