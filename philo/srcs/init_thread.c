/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:35:56 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/23 17:09:24 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	join_threads(int num, t_philo *threads)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_join(threads[i].threads, NULL))
			return (false);
		i++;
	}
	free(threads);
	return (true);
}

bool	init_mutex(t_data *data)
{
	int		i;
	bool	ret;

	i = 0;
	ret = true;
	if (pthread_mutex_init(&data->display, NULL))
		return (false);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->philos[i].fork, NULL))
		{
			ret = false;
			break ;
		}
		if (pthread_mutex_init(&data->philos[i].eat_or_die, NULL))
		{
			ret = false;
			break ;
		}
		i++;
	}
	return (ret);
}

bool	create_thread(t_data *data, char oddenven)
{
	int		i;
	bool	ret;

	ret = true;
	if (oddenven == 'o')
		i = 0;
	else
		i = 1;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philos[i].threads, NULL,
				&start_philo, &(data->philos[i])))
		{
			ret = false;
			break ;
		}
		usleep(500);
		i = i + 2;
	}
	return (ret);
}

bool	init_thread(t_data *data)
{
	bool	ret;
	int		i;

	i = 0;
	ret = true;
	if (!init_mutex(data))
		return (false);
	if (!create_thread(data, 'o'))
		return (false);
	if (!create_thread(data, 'e'))
		return (false);
	if (ret)
		ret = join_threads(data->nb_philo, data->philos);
	return (ret);
}
