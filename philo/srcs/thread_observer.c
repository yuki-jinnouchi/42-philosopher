/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_observer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:29:34 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/11 12:31:04 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_someone_dead(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->num_philos)
	{
		if (is_philo_starving(&data->philos[i], data))
		{
			philo = &data->philos[i];
			pthread_mutex_lock(&philo->finished_mutex);
			philo->finished = TRUE;
			pthread_mutex_unlock(&philo->finished_mutex);
			make_everyone_finish(data);
			print_status(philo, DEAD);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

//check if all philos finished eating and kill if it's true
int	is_everyone_finish(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->num_philos)
	{
		if (is_philo_finished(&data->philos[i]))
			count ++;
		i++;
	}
	if (count == data->num_philos)
	{
		make_everyone_finish(data);
		return (TRUE);
	}
	return (FALSE);
}

void	make_everyone_finish(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->num_philos)
	{
		philo = &data->philos[i];
		pthread_mutex_lock(&philo->finished_mutex);
		philo->finished = TRUE;
		pthread_mutex_unlock(&philo->finished_mutex);
		i++;
	}
	pthread_mutex_lock(&data->finished_mutex);
	data->finished = TRUE;
	pthread_mutex_unlock(&data->finished_mutex);
}

void	*observer(void *val)
{
	t_data	*data;

	data = (t_data *)val;
	while (is_all_finished(data) == FALSE)
	{
		if (is_everyone_finish(data) == TRUE || is_someone_dead(data) == TRUE)
		{
			pthread_mutex_lock(&data->finished_mutex);
			data->finished = TRUE;
			pthread_mutex_unlock(&data->finished_mutex);
		}
		else if (!is_all_finished(data))
			msleep(5);
	}
	return (NULL);
}
