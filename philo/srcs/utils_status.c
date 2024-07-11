/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_status_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:41:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/10 20:01:15 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_starving(t_philo *philo, t_data *data)
{
	uint64_t	duration;

	duration = get_time_from_last_eat(philo, data);
	if ((int) duration > data->time_to_die && \
		if_philo_finished(philo) == FALSE)
		return (TRUE);
	return (FALSE);
}

// int	is_philo_finished(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->finished_mutex);
// 	if (philo->finished == TRUE)
// 	{
// 		pthread_mutex_unlock(&philo->finished_mutex);
// 		return (TRUE);
// 	}
// 	pthread_mutex_unlock(&philo->finished_mutex);
// 	return (FALSE);
// }

// int	is_all_finished(t_data *data)
// {
// 	pthread_mutex_lock(&data->all_finished_mutex);
// 	if (data->all_finished == TRUE)
// 	{
// 		pthread_mutex_unlock(&data->all_finished_mutex);
// 		return (TRUE);
// 	}
// 	pthread_mutex_unlock(&data->all_finished_mutex);
// 	return (FALSE);
// }

// void	kill_everyone(t_data *data)
// {
// 	int		i;
// 	t_philo	*philo;

// 	i = 0;
// 	while (i < data->num_philos)
// 	{
// 		philo = data->philos[i];
// 		pthread_detach(data->threads[i]);
// 		i++;
// 	}
// }
