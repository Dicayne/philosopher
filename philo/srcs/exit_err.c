/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:51:33 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/16 15:32:19 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	print_err(char *str)
{
	write(2, str, ft_strlen(str));
}

int	exit_err(int status, t_data *data)
{
	print_err("\033[4;31mERROR\033[0m: ");
	if (status == 1)
	{
		print_err("Wrong Number of Arguments: ./philo_one \033[0;34m");
		print_err("[nb_of_philo] [t_to_die] [t_to_eat] [t_to_sleep]\n");
	}
	if (status == 2)
		print_err("Need Positive Integer Arguments, Greater Than 0\n");
	if (status == 3)
		print_err("Can't Allocate Memory\n");
	if (status == 4)
	{
		free(data->philos);
		print_err("Can't Create Thread\n");
	}
	return (EXIT_FAILURE);
}
