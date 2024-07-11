/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:30:13 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 17:41:24 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	if (if_philo_dead(philo) || if_philo_finished(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		return (FAILURE);
	}
	printf("%llu %d has taken a fork\n", get_time_from_start(philo->data), philo->num_id);
	return (SUCCESS);
}

int	philosopher_take_left_fork(t_philo *philo)
{
	if (philo->right_fork == philo->left_fork)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (FAILURE);
	}
	pthread_mutex_lock(philo->left_fork);
	if (if_philo_dead(philo) || if_philo_finished(philo) || \
		philo->right_fork == philo->left_fork)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (FAILURE);
	}
	printf("%llu %d has taken a fork\n", get_time_from_start(philo->data), philo->num_id);
	return (SUCCESS);
}

int	philosopher_sleep(t_philo *philo)
{
	if (if_philo_dead(philo) == TRUE || if_philo_finished(philo) == TRUE)
		return (FAILURE);
	printf("%llu %d is sleeping\n", get_time_from_start(philo->data), philo->num_id);
	msleep(philo->data->time_to_sleep);
	if (if_philo_dead(philo) == TRUE || if_philo_finished(philo) == TRUE)
		return (FAILURE);
	printf("%llu %d is thinking\n", get_time_from_start(philo->data), philo->num_id);
	return (SUCCESS);
}

int	philosopher_eat(t_philo *philo)
{
	if (if_philo_dead(philo) == TRUE || if_philo_finished(philo) == TRUE)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (FAILURE);
	}
	printf("%llu %d is eating\n", get_time_from_start(philo->data), philo->num_id);
	pthread_mutex_lock(&philo->last_eat_mutex);
	philo->last_eat = get_current_time();
	pthread_mutex_unlock(&philo->last_eat_mutex);
	msleep(philo->data->time_to_eat);
	philo->eat_count++;
	if (philo->data->max_time_eat != -1 && philo->eat_count >= philo->data->max_time_eat)
	{
		pthread_mutex_lock(&philo->finished_mutex);
		philo->finished = TRUE;
		pthread_mutex_unlock(&philo->finished_mutex);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (SUCCESS);
}

void	*philosopher(void *val)
{
	t_philo	*philo;

	philo = (t_philo *)val;
	if (philo->num_id % 2 == 1 && philo->eat_count == 0)
		msleep(2);
	while (!if_philo_dead(philo) && !if_philo_finished(philo))
	{
		if (philosopher_take_left_fork(philo) == FAILURE)
			return (NULL);
		if (philosopher_take_right_fork(philo) == FAILURE)
			return (NULL);
		if (philosopher_eat(philo) == FAILURE)
			return (NULL);
		if (philosopher_sleep(philo) == FAILURE)
			return (NULL);
	}
	return (NULL);
}
