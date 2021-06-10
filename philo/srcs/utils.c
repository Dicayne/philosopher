/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:57:03 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/07 16:08:33 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	find_id_fork(t_philo *philo, int *id_left)
{
	if (philo->id == 1)
		*id_left = philo->data->philos[philo->data->nb_philo - 1].id;
	else if (philo->id == philo->data->nb_philo)
		*id_left = philo->id - 1;
	else
		*id_left = philo->id - 1;
}

int		ft_atoi(const char *str)
{
	int i;
	int less;
	int nb_ret;

	i = 0;
	less = 1;
	nb_ret = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			less = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb_ret = nb_ret * 10 + (str[i] - '0');
		i++;
	}
	return (nb_ret * less);
}

bool	isnum(char* str)
{
	int i;
	bool ret;

	i = 0;
	ret = true;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ret = false;
			break;
		}
		i++;
	}
	return (ret);
}
