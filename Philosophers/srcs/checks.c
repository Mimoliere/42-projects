/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:32:54 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/22 14:44:29 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i++]) <= 0)
			return (0);
	}
	return (1);
}

int	check_mutexes(t_monitor *monitor)
{
	if (pthread_mutex_init(&(monitor->dead), NULL) != 0)
		return (0);
	if (pthread_mutex_init(&(monitor->write), NULL) != 0)
		return (pthread_mutex_destroy(&(monitor->dead)), 0);
	if (pthread_mutex_init(&(monitor->time), NULL) != 0)
		return (pthread_mutex_destroy(&(monitor->dead)),
			pthread_mutex_destroy(&(monitor->write)), 0);
	if (pthread_mutex_init(&(monitor->meals), NULL) != 0)
		return (pthread_mutex_destroy(&(monitor->dead)),
			pthread_mutex_destroy(&(monitor->write)),
			pthread_mutex_destroy(&(monitor->time)), 0);
	if (pthread_mutex_init(&(monitor->turns), NULL) != 0)
		return (pthread_mutex_destroy(&(monitor->dead)),
			pthread_mutex_destroy(&(monitor->write)),
			pthread_mutex_destroy(&(monitor->time)),
			pthread_mutex_destroy(&(monitor->meals)), 0);
	return (1);
}

int	check_meals(t_monitor *monitor)
{
	int	res;

	res = 1;
	pthread_mutex_lock(&(monitor->meals));
	if (monitor->nb_eat != -1
		&& monitor->nbr_meals >= monitor->nb_eat * monitor->philo_nb)
		res = 0;
	pthread_mutex_unlock(&(monitor->meals));
	return (res);
}

int	is_turn(t_philo *philo)
{
	pthread_mutex_lock(&philo->monitor->turns);
	if (philo->monitor->turn > 0)
	{
		philo->monitor->turn--;
		pthread_mutex_unlock(&philo->monitor->turns);
		return (1);
	}
	pthread_mutex_unlock(&philo->monitor->turns);
	return (0);
}
