/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:49:25 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/16 15:36:23 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].arg.time_die = data->arg.time_die;
		philo[i].arg.time_eat = data->arg.time_eat;
		philo[i].arg.time_sleep = data->arg.time_sleep;
		philo[i].arg.ntpe_tot = data->arg.ntpe_tot;
		philo[i].arg.time_start = data->arg.time_start;
		philo[i].ntpe = 0;
		philo[i].time_without_eat = get_time(true, philo->time_without_eat);
		philo[i].data = data;
		i++;
	}
}

bool	init(t_data *data, char **av, int ac)
{
	data->arg.time_start = get_time(true, data->arg.time_start);
	data->nb_philo = ft_atoi(av[0]);
	data->arg.time_die = ft_atoi(av[1]);
	data->arg.time_eat = ft_atoi(av[2]);
	data->arg.time_sleep = ft_atoi(av[3]);
	data->is_philo_dead = false;
	if (ac == 6)
		data->arg.ntpe_tot = ft_atoi(av[4]);
	else
		data->arg.ntpe_tot = -1;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (false);
	init_philo(data, data->philos);
	return (true);
}
