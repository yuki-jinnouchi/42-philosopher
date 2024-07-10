/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 07:39:26 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos_forks(t_data *data, t_philo *philo, int i)
{
	philo->right_fork = &data->forks[i];
	philo->left_fork = &data->forks[i + 1];
	if (i == data->num_philos - 1)
		philo->left_fork = &data->forks[0];
	return (SUCCESS);
}

int	init_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->num_philos)
	{
		philo = &data->philos[i];
		philo->num_id = i + 1;
		philo->thread_id = data->thread_ids[i];
		init_philos_forks(data, philo, i);
		philo->eat_count = 0;
		philo->last_eat = data->start_time;
		pthread_mutex_init(&philo->last_eat_mutex, 0);
		philo->dead = FALSE;
		pthread_mutex_init(&philo->dead_mutex, 0);
		philo->finished = FALSE;
		pthread_mutex_init(&philo->finished_mutex, 0);
		// philo->time_to_die = (uint64_t) data->time_to_die;
		// philo->time_to_eat = (uint64_t) data->time_to_eat;
		// philo->time_to_sleep = (uint64_t) data->time_to_sleep;
		// philo->max_time_eat = data->max_time_eat;
		philo->data = data;
		i++;
	}
	return (SUCCESS);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
		pthread_mutex_init(&data->forks[i++], 0);
	return (SUCCESS);
}

int	init_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->thread_ids[i], NULL, \
			*philosopher, &data->philos[i]) != 0)
			return (FAILURE);
		i++;
	}
	if (pthread_create(&data->thread_ids[i], NULL, \
		*observer, data) != 0)
		return (FAILURE);
	return (SUCCESS);
}
