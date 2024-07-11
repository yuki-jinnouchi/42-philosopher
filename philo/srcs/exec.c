/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:07:37 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 16:55:55 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exec(t_data *data)
{
	int		i;

	if (init_threads(data) == FAILURE)
		return (FAILURE);
	while (!if_all_finished(data))
		msleep(1);
	pthread_join(data->thread_ids[data->num_philos], NULL);
	return (SUCCESS);
}
