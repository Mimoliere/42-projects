/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:58:12 by bguerrou          #+#    #+#             */
/*   Updated: 2025/06/06 13:05:50 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_monitor
{
	int							philo_nb;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							nb_eat;
	int							nbr_meals;
	int							death;
	int							start;
	int							turn;
	pthread_mutex_t				dead;
	pthread_mutex_t				turns;
	pthread_mutex_t				write;
	pthread_mutex_t				time;
	pthread_mutex_t				meals;
	pthread_t					thread;
	struct s_philo				*philo;
}	t_monitor;

typedef struct s_philo
{
	int					nb;
	int					died;
	int					waiting_start;
	pthread_t			thread;
	pthread_mutex_t		wait;
	pthread_mutex_t		fork;
	struct s_philo		*next;
	struct s_philo		*prev;
	struct s_monitor	*monitor;
}	t_philo;

# define FORK_ERR "Error: failed to create fork mutex\n"
# define MALLOC_ERR "Error: failed to allocate memory\n"

void		*living(void *arg);
t_philo		*set_attributes(t_philo *prev, int i);

int			philo_error(char *str, int code);

int			ft_strlen(const char *s);
int			ft_atoi(const char *nptr);
void		clear_philos(t_philo **philo, int nb, int moni);
void		print(char *str, int time, int nb, t_philo *philo);
int			ft_usleep(t_philo *philo, int longer);

int			check_args(int argc, char **argv);
int			check_mutexes(t_monitor *monitor);
int			check_meals(t_monitor *monitor);
int			is_turn(t_philo *philo);

int			get_time(int start);
// int			check_time(int start, t_philo *philo);
int			is_dead(t_monitor *monitor);

void		init_data(int argc, char **argv, t_monitor *monitor);
t_monitor	*link_monitor(t_philo *philo, int argc, char **argv);
void		*philo_died(void *arg);
int			longest_wait(t_philo *philo);

void		*living(void *arg);
int			eating(t_philo *philo);
int			take_fork(t_philo *philo);
void		lock(t_philo *philo, pthread_mutex_t *fork, int *count);
void		unlock(t_philo *philo, int *count);

#endif
