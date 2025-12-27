/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:54:21 by bguerrou          #+#    #+#             */
/*   Updated: 2025/06/05 16:30:54 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*set_attributes(t_philo *prev, int i)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->prev = prev;
	philo->nb = i;
	philo->died = 0;
	philo->waiting_start = get_time(0);
	if (pthread_mutex_init(&(philo->fork), NULL) != 0)
		return (free(philo), NULL);
	else if (pthread_mutex_init(&(philo->wait), NULL) != 0)
		return (pthread_mutex_destroy(&(philo->fork)), free(philo), NULL);
	philo->next = NULL;
	return (philo);
}

t_philo	*init_philos(char **argv)
{
	t_philo	*philo;
	t_philo	*tmp;
	t_philo	*prev;
	int		i;
	int		philo_nb;

	philo_nb = ft_atoi(argv[1]);
	i = 1;
	philo = set_attributes(NULL, i++);
	if (!philo)
		return (NULL);
	prev = philo;
	while (i <= philo_nb)
	{
		tmp = set_attributes(prev, i);
		if (!tmp)
			return (clear_philos(&philo, i, 0), NULL);
		prev->next = tmp;
		prev = tmp;
		i++;
	}
	philo->prev = prev;
	prev->next = philo;
	return (philo);
}

int	joining(t_philo *philo, t_monitor *monitor)
{
	int		i;
	t_philo	*current;

	i = 1;
	current = philo;
	while (i <= monitor->philo_nb)
	{
		if (pthread_join(current->thread, NULL) != 0)
			return (1);
		current = current->next;
		i++;
	}
	if (pthread_join(monitor->thread, NULL) != 0)
		return (1);
	return (0);
}

int	run_philos(t_philo *philo)
{
	int		i;
	t_philo	*current;

	i = 1;
	if (pthread_create(&philo->monitor->thread, NULL, philo_died, philo) != 0)
		return (1);
	current = philo;
	while (i <= philo->monitor->philo_nb)
	{
		if (pthread_create(&current->thread, NULL, living, current) != 0)
			return (1);
		current = current->next;
		i++;
	}
	return (joining(philo, philo->monitor));
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_monitor	*monitor;
	int			err;

	if (argc < 5 || argc > 6 || !check_args(argc, argv))
		return (philo_error("Error: invalid arguments\n", 1));
	philo = init_philos(argv);
	if (!philo)
		return (philo_error(MALLOC_ERR, 2));
	monitor = link_monitor(philo, argc, argv);
	if (!monitor)
		return (clear_philos(&philo, monitor->philo_nb, 0),
			philo_error(MALLOC_ERR, 2));
	err = run_philos(philo);
	clear_philos(&philo, monitor->philo_nb, 1);
	free(monitor);
	if (err != 0)
		return (philo_error("Error: failed to create thread\n", 3));
}
