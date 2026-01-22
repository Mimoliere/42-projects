/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:04:54 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/22 14:44:19 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	unlock(t_philo *philo, int *count)
{
	if (*count >= 1)
		pthread_mutex_unlock(&(philo->fork));
	if (*count == 2)
	{
		pthread_mutex_unlock(&(philo->next->fork));
		pthread_mutex_lock(&philo->monitor->turns);
		philo->monitor->turn++;
		pthread_mutex_unlock(&philo->monitor->turns);
	}
}

static void	lock(t_philo *philo, pthread_mutex_t *fork, int *count)
{
	pthread_mutex_lock(fork);
	if (!is_dead(philo->monitor) && check_meals(philo->monitor))
	{
		print("has taken a fork", philo->nb, philo);
		(*count)++;
	}
	else
		pthread_mutex_unlock(fork);
}

static int	take_fork(t_philo *philo)
{
	int	count;

	count = 0;
	if (philo->nb % 2 == 0)
		usleep(200);
	while (!is_turn(philo) && !is_dead(philo->monitor)
		&& check_meals(philo->monitor))
		usleep(100);
	if (!is_dead(philo->monitor) && check_meals(philo->monitor))
	{
		lock(philo, &(philo->fork), &count);
		if (!is_dead(philo->monitor) && check_meals(philo->monitor))
			lock(philo, &(philo->next->fork), &count);
	}
	return (count);
}

static int	eating(t_philo *philo)
{
	int	nb;
	int	count;

	nb = philo->nb;
	count = take_fork(philo);
	if (!is_dead(philo->monitor) && count == 2 && check_meals(philo->monitor))
	{
		pthread_mutex_lock(&philo->wait);
		philo->waiting_start = get_time(0);
		pthread_mutex_unlock(&philo->wait);
		print("is eating", nb, philo);
		pthread_mutex_lock(&philo->monitor->meals);
		philo->monitor->nbr_meals++;
		pthread_mutex_unlock(&philo->monitor->meals);
		ft_usleep(philo->monitor->time_to_eat);
	}
	unlock(philo, &count);
	if (count < 2 || !check_meals(philo->monitor))
		return (0);
	return (1);
}

void	*living(void *arg)
{
	int		nb;
	t_philo	*philo;

	philo = (t_philo *)arg;
	nb = philo->nb;
	pthread_mutex_lock(&philo->wait);
	philo->waiting_start = get_time(0);
	pthread_mutex_unlock(&philo->wait);
	while (!is_dead(philo->monitor) && check_meals(philo->monitor))
	{
		print("is thinking", nb, philo);
		if (!eating(philo))
			return (NULL);
		print("is sleeping", nb, philo);
		if (!is_dead(philo->monitor) && check_meals(philo->monitor))
			ft_usleep(philo->monitor->time_to_sleep);
	}
	return (NULL);
}
