/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:56:45 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/03 11:55:48 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

bool	check_args(char **av)
{
	int		i;
	bool	ret;

	i = 0;
	ret = true;
	while (av[i])
	{
		if (!isnum(av[i]))
		{
			ret = false;
			break;
		}
		i++;
	}
	return (ret);
}
