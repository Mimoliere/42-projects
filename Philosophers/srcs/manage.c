/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:12:24 by bguerrou          #+#    #+#             */
/*   Updated: 2025/06/05 13:55:31 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_time(int start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_usec / 1000 + time.tv_sec * 1000) - start);
}

// int	check_time(int start, t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->monitor->time);
// 	if (get_time(start) > philo->monitor->time_to_die + 1)
// 	{
// 		philo->died = 1;
// 		pthread_mutex_lock(&philo->monitor->dead);
// 		philo->monitor->death = 1;
// 		pthread_mutex_unlock(&philo->monitor->dead);
// 		pthread_mutex_unlock(&philo->monitor->time);
// 		return (0);
// 	}
// 	pthread_mutex_unlock(&philo->monitor->time);
// 	return (1);
// }

int	is_dead(t_monitor *monitor)
{
	int	died;

	pthread_mutex_lock(&monitor->dead);
	died = monitor->death;
	pthread_mutex_unlock(&monitor->dead);
	return (died);
}
