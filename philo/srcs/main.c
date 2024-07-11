/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:41:08 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 17:40:16 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exec(t_data *data)
{
	int		i;

	if (init_threads(data) == FAILURE)
		return (FAILURE);
	while (is_all_finished(data) == FALSE)
		msleep(1);
	i = 0;
	while (i < data->num_philos + 1)
	{
		pthread_join(data->thread_ids[i], NULL);
		i++;
	}
	return (SUCCESS);
}

/*
get argment and process
- number_of_philosophers (n)
- time_to_die (ms)
- time_to_eat (ms)
- time_to_sleep (ms)
- number_of_times_each_philosopher_must_eat (n/optional)
*/
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || 6 < argc)
		exit_wo_perror("argment should be 4 or 5 ints", NULL);
	data = (t_data *) malloc(sizeof(t_data));
	if (data == NULL)
		return (FAILURE);
	init_data_args(argc, argv, data);
	init_data_malloc(data);
	init_forks(data);
	init_philos(data);
	exec(data);
	free_data(data);
	return (SUCCESS);
}
