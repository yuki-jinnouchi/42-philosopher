/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_observer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:29:34 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 17:40:53 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// //check dead flag and kill everything if it's true
// uint64_t	get_last_eat(t_philo *philo)
// {
// 	uint64_t	last_eat;

// 	pthread_mutex_lock(&philo->last_eat_mutex);
// 	last_eat = philo->last_eat;
// 	pthread_mutex_unlock(&philo->last_eat_mutex);
// 	return (last_eat);
// }

int	if_someone_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		// printf("%llu observer checks if philo %d is dead\n", get_time_from_start(data), data->philos[i].num_id);
		if (is_philo_starving(&data->philos[i], data))
		{
			pthread_mutex_lock(&data->philos[i].dead_mutex);
			data->philos[i].dead = TRUE;
			pthread_mutex_unlock(&data->philos[i].dead_mutex);
			finish_everyone(data);
			printf("duration %llu\n", get_time_from_last_eat(&data->philos[i], data));
			printf("%llu %d died\n", get_time_from_start(data), data->philos[i].num_id);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

//check if all philos finished eating and kill if it's true
int	if_everyone_finish(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->num_philos)
	{
		if (if_philo_dead(&data->philos[i]) || \
			if_philo_finished(&data->philos[i]))
			count ++;
		i++;
	}
	if (count == data->num_philos)
	{
		finish_everyone(data);
		return (TRUE);
	}
	return (FALSE);
}

void	finish_everyone(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->philos[i].finished_mutex);
		data->philos[i].finished = TRUE;
		pthread_mutex_unlock(&data->philos[i].finished_mutex);
		// pthread_join(data->thread_ids[i], NULL);
		i++;
	}
}

void	*observer(void *val)
{
	t_data	*data;

	data = (t_data *)val;
	while (!if_all_finished(data))
	{
		if (if_everyone_finish(data) || if_someone_dead(data))
		{
			pthread_mutex_lock(&data->finished_mutex);
			data->finished = TRUE;
			pthread_mutex_unlock(&data->finished_mutex);
		}
		else if (!if_all_finished(data))
			msleep(1);
	}
	return (NULL);
}
