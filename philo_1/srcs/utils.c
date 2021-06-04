/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:57:03 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/03 12:09:36 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
