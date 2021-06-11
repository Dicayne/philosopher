/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:57:03 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/11 16:14:48 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	display_status(t_philo *philo, char *status)
{
	unsigned int time;

	pthread_mutex_lock(&philo->data->display);
	time = get_time(false, philo->arg.time_start);
	if (!ft_strcmp(status, "EAT"))
		printf("%d\t %d:\033[32m is eating\n", time, philo->id);
	else if (!ft_strcmp(status, "SLEEP"))
		printf("%d\t %d:\033[33m is sleeping\n", time, philo->id);
	else if (!ft_strcmp(status, "THINK"))
		printf("%d\t %d:\033[34m is thinking\n", time, philo->id);
	else if (!ft_strcmp(status, "DIE"))
		printf("%d\t %d:\033[0;31m died\n", time, philo->id);
	else if (!ft_strcmp(status, "FORK"))
		printf("%d\t %d: has taken a fork\n", time, philo->id);
	if (ft_strcmp(status, "DIE"))
		pthread_mutex_unlock(&philo->data->display);
	printf("\033[0m");
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	if (s1[0] == '\0')
		return ((unsigned char)s1[0] - (unsigned char)s2[0]);
	return (0);
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
