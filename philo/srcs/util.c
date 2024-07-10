/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:11:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 17:42:08 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*atoi for only positive int. undef for over INT_MAX*/
int	philo_atoi(const char *nptr)
{
	int	count;
	int	number;

	count = 0;
	number = 0;
	while ('0' <= nptr[count] && nptr[count] <= '9')
	{
		number = (number * 10) + ((nptr[count] - '0'));
		count++;
	}
	if (nptr[count] != '\0')
		return (FAILURE);
	return (number);
}

int	if_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->dead_mutex);
	if (philo->dead == TRUE)
	{
		pthread_mutex_unlock(&philo->dead_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->dead_mutex);
	return (FALSE);
}

int	if_philo_finished(t_philo *philo)
{
	pthread_mutex_lock(&philo->finished_mutex);
	if (philo->finished == TRUE)
	{
		pthread_mutex_unlock(&philo->finished_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->finished_mutex);
	return (FALSE);
}

int	if_all_finished(t_data *data)
{
	pthread_mutex_lock(&data->finished_mutex);
	if (data->finished == TRUE)
	{
		pthread_mutex_unlock(&data->finished_mutex);
		return (TRUE);
	}
	pthread_mutex_unlock(&data->finished_mutex);
	return (FALSE);
}
