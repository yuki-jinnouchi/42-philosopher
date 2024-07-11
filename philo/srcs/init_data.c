/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:05:27 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/15 20:38:26 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*valid and put num for args*/
int	init_data_args(int argc, char **argv, t_data *data)
{
	data->num_philos = philo_atoi(argv[1]);
	data->time_to_die = philo_atoi(argv[2]);
	data->time_to_eat = philo_atoi(argv[3]);
	data->time_to_sleep = philo_atoi(argv[4]);
	if (data->num_philos == FAILURE || data->time_to_die == FAILURE || \
		data->time_to_eat == FAILURE || data->time_to_sleep == FAILURE)
		exit_wo_perror("arg int (1-4) valid error", data);
	if (argc == 6)
	{
		data->max_time_eat = philo_atoi(argv[5]);
		if (data->max_time_eat == FAILURE)
			exit_wo_perror("arg int (5) valid error", data);
	}
	else
		data->max_time_eat = -1;
	data->start_time = get_current_time();
	pthread_mutex_init(&data->finished_mutex, 0);
	data->finished = FALSE;
	return (SUCCESS);
}

int	init_data_malloc(t_data *data)
{
	data->thread_ids = (pthread_t *) \
		malloc(sizeof(pthread_t) * (data->num_philos + 1));
	data->philos = (t_philo *) \
		malloc(sizeof(t_philo) * data->num_philos);
	data->forks = (pthread_mutex_t *) \
		malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (data->thread_ids == NULL || data->philos == NULL || data->forks == NULL)
		exit_wo_perror("data malloc error", data);
	return (SUCCESS);
}
