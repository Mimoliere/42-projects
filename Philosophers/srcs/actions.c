/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:04:54 by bguerrou          #+#    #+#             */
/*   Updated: 2025/06/06 13:21:33 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*living(void *arg)
{
	int		nb;
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->monitor->start = get_time(0);
	nb = philo->nb;
	while (!is_dead(philo->monitor) && check_meals(philo->monitor))
	{
		print("is thinking", get_time(philo->monitor->start), nb, philo);
		if (!eating(philo))
			return (NULL);
		pthread_mutex_lock(&philo->wait);
		philo->waiting_start = get_time(0);
		pthread_mutex_unlock(&philo->wait);
		print("is sleeping", get_time(philo->monitor->start), nb, philo);
        if (!is_dead(philo->monitor) && check_meals(philo->monitor))
		    ft_usleep(philo, philo->monitor->time_to_sleep * 1000);
	}
	return (NULL);
}

int	eating(t_philo *philo)
{
	int	nb;
	int	count;

	nb = philo->nb;
	count = take_fork(philo);
	if (!is_dead(philo->monitor) && count == 2 && check_meals(philo->monitor))
	{
    	print("is eating", get_time(philo->monitor->start), nb, philo);
		pthread_mutex_lock(&philo->monitor->meals);
		philo->monitor->nbr_meals++;
		pthread_mutex_unlock(&philo->monitor->meals);
        ft_usleep(philo, philo->monitor->time_to_eat * 1000);
	}
	unlock(philo, &count);
	if (count < 2 || !check_meals(philo->monitor))
		return (0);
	return (1);
}

int	take_fork(t_philo *philo)
{
	int	count;

	count = 0;
	while (!is_turn(philo) && !is_dead(philo->monitor) && check_meals(philo->monitor))
		usleep(5000);
	if (philo->nb % 2 != 0 && !is_dead(philo->monitor) && check_meals(philo->monitor))
		lock(philo, &(philo->fork), &count);
	else if (!is_dead(philo->monitor) && check_meals(philo->monitor))
		lock(philo, &(philo->next->fork), &count);
	usleep(100);
	if (philo->nb % 2 != 0 && !is_dead(philo->monitor) && check_meals(philo->monitor))
		lock(philo, &(philo->next->fork), &count);
	else if (!is_dead(philo->monitor) && check_meals(philo->monitor))
		lock(philo, &(philo->fork), &count);
	return (count);
}

void	lock(t_philo *philo, pthread_mutex_t *fork, int *count)
{
	pthread_mutex_lock(fork);
	if (!is_dead(philo->monitor) && check_meals(philo->monitor))
	{
		print("has taken a fork", get_time(philo->monitor->start), philo->nb, philo);
		(*count)++;
	}
	else
		pthread_mutex_unlock(fork);
}

void	unlock(t_philo *philo, int *count)
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
