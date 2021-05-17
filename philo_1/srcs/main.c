/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:35:48 by vmoreau           #+#    #+#             */
/*   Updated: 2021/05/07 12:58:11 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int main(int ac, char **av)
{
	(void)av;
	if (ac == 4 || ac == 5)
		printf("Let's go\n");
	else
	{
		printf("Wrong Number of imput: ./philo_one [time_to_die] ");
		printf("[time_to_eat] [time_to_sleep]\n");
	}
	return (0);
}
