/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:24:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 16:54:31 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(data->philos[i].right_fork);
		pthread_mutex_destroy(&data->philos[i].last_eat_mutex);
		pthread_mutex_destroy(&data->philos[i].finished_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->finished_mutex);
	if (data->thread_ids != NULL)
		free(data->thread_ids);
	if (data->philos != NULL)
		free(data->philos);
	if (data->forks != NULL)
		free(data->forks);
	free(data);
}
