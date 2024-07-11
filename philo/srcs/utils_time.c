/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:08:32 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/10 10:47:45 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*get uint64_t tye timestamp from gettimeofday()*/
uint64_t	get_current_time(void)
{
	struct timeval	tv;
	uint64_t		time;

	if (gettimeofday(&tv, NULL))
	{
		printf("gettimeofday error\n");
		return (0);
	}
	time = (uint64_t)(tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

uint64_t	get_time_from_start(t_data *data)
{
	struct timeval	tv;
	uint64_t		time;

	if (gettimeofday(&tv, NULL))
	{
		printf("gettimeofday error\n");
		return (0);
	}
	time = (uint64_t)(tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time = time - data->start_time;
	return (time);
}

uint64_t	get_time_from_last_eat(t_philo *philo, t_data *data)
{
	uint64_t	time;

	time = get_current_time();
	pthread_mutex_lock(&philo->last_eat_mutex);
	time = time - philo->last_eat;
	pthread_mutex_unlock(&philo->last_eat_mutex);
	return (time);
}

void	msleep(uint64_t time)
{
	usleep(time * 1000);
	return ;
}
