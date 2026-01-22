/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 22:28:03 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/22 14:45:16 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	unsigned char	*p;
	int				n;
	int				i;
	int				s;

	p = (unsigned char *) nptr;
	i = 0;
	n = 0;
	s = 1;
	while (p[i] == ' ' || (p[i] >= 9 && p[i] <= 13))
		i++;
	if (p[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (p[i] == '+')
		i++;
	while (p[i])
	{
		if (p[i] < '0' || p[i] > '9')
			return (0);
		n = 10 * n + (p[i++] - '0');
	}
	return (n * s);
}

void	clear_philos(t_philo **philo, int nb, int moni)
{
	t_philo	*tmp;
	t_philo	*next;
	int		i;

	i = 0;
	tmp = *philo;
	if (moni)
	{
		pthread_mutex_destroy(&((*philo)->monitor->dead));
		pthread_mutex_destroy(&((*philo)->monitor->write));
		pthread_mutex_destroy(&((*philo)->monitor->time));
		pthread_mutex_destroy(&((*philo)->monitor->meals));
		pthread_mutex_destroy(&((*philo)->monitor->turns));
	}
	free((*philo)->monitor);
	while (i++ < nb)
	{
		next = tmp->next;
		pthread_mutex_destroy(&tmp->fork);
		pthread_mutex_destroy(&tmp->wait);
		free(tmp);
		tmp = NULL;
		tmp = next;
	}
}

void	print(char *str, int nb, t_philo *philo)
{
	int	time;

	if (!is_dead(philo->monitor) && check_meals(philo->monitor))
	{
		pthread_mutex_lock(&philo->monitor->write);
		time = get_time(philo->monitor->start);
		printf("%i %i %s\n", time, nb, str);
		pthread_mutex_unlock(&philo->monitor->write);
	}
}

void	ft_usleep(size_t longer)
{
	size_t	start;

	start = get_time(0);
	while ((get_time(0) - start) < longer)
		usleep(500);
}
