/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:15:45 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/22 14:44:42 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_data(int argc, char **argv, t_monitor *monitor)
{
	monitor->philo_nb = ft_atoi(argv[1]);
	monitor->time_to_die = ft_atoi(argv[2]);
	monitor->time_to_eat = ft_atoi(argv[3]);
	monitor->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		monitor->nb_eat = ft_atoi(argv[5]);
	else
		monitor->nb_eat = -1;
	monitor->nbr_meals = 0;
	monitor->death = 0;
	monitor->start = 0;
	monitor->turn = monitor->philo_nb - 1;
}

t_monitor	*link_monitor(t_philo *philo, int argc, char **argv)
{
	t_monitor	*monitor;
	t_philo		*current;
	int			i;

	monitor = malloc(sizeof(t_monitor));
	if (!monitor)
		return (NULL);
	if (!check_mutexes(monitor))
		return (free(monitor), NULL);
	init_data(argc, argv, monitor);
	monitor->philo = philo;
	current = philo;
	i = 0;
	while (i < monitor->philo_nb)
	{
		current->monitor = monitor;
		current = current->next;
		i++;
	}
	return (monitor);
}

static void	check_eat(t_philo *philo, t_monitor *monitor)
{
	int	since_last_meal;

	pthread_mutex_lock(&philo->wait);
	since_last_meal = get_time(philo->waiting_start);
	pthread_mutex_unlock(&philo->wait);
	if (!philo->died
		&& since_last_meal > monitor->time_to_die)
	{
		philo->died = 1;
		pthread_mutex_lock(&monitor->dead);
		monitor->death = 1;
		pthread_mutex_unlock(&monitor->dead);
	}
}

void	*philo_died(void *arg)
{
	t_philo		*philo;
	t_monitor	*monitor;

	philo = (t_philo *)arg;
	monitor = philo->monitor;
	while (!is_dead(monitor) && check_meals(monitor))
	{
		philo = philo->next;
		check_eat(philo, monitor);
	}
	pthread_mutex_lock(&philo->monitor->write);
	if (!check_meals(monitor))
		printf("Yee haw !\n");
	else
		printf("%i %i died\n", get_time(monitor->start), philo->nb);
	pthread_mutex_unlock(&philo->monitor->write);
	return (NULL);
}
