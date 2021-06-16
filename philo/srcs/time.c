/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:11:27 by vmoreau           #+#    #+#             */
/*   Updated: 2021/06/16 15:40:32 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int	get_time(bool start, unsigned int time_start)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (long)(tv.tv_sec * 1000 + tv.tv_usec / 1000);
	if (start)
		return (time);
	else
		return (time - time_start);
}
