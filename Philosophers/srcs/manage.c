/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:12:24 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/15 15:28:32 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_time(int start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000 + time.tv_sec * 1000) - start);
}

int	is_dead(t_monitor *monitor)
{
	int	died;

	pthread_mutex_lock(&monitor->dead);
	died = monitor->death;
	pthread_mutex_unlock(&monitor->dead);
	return (died);
}
