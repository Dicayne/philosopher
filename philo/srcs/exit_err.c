/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:51:33 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/11 16:03:05 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	exit_err(int status, t_data *data)
{
	printf("\033[4;31mERROR\033[0m: ");
	if (status == 1)
	{
		printf("Wrong Number of Arguments: ./philo_one \033[0;34m");
		printf("[nb_of_philo] [time_to_die] [time_to_eat] [time_to_sleep]\n");
	}
	if (status == 2)
		printf("Need Positive Integer Arguments, Greater Than 0\n");
	if (status == 3)
		printf("Can't Allocate Memory\n");
	if (status == 4)
	{
		free(data->philos);
		printf("Can't Create Thread\n");
	}
	exit(EXIT_FAILURE);
}
