/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:58:16 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/11 12:04:56 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_status(t_philo *philo, t_philo_status status)
{
    uint64_t time;

    time = get_time_from_start(philo->data);
    if (status == TAKE_RIGHT_FORK || status == TAKE_LEFT_FORK)
        printf("%llu %d has taken a fork\n", time, philo->num_id);
    if (status == THINKING)
        printf("%llu %d is thinking\n", time, philo->num_id);
    else if (status == EATING)
        printf("%llu %d is eating\n", time, philo->num_id);
    else if (status == SLEEPING)
        printf("%llu %d is sleeping\n", time, philo->num_id);
    else if (status == DEAD)
        printf("%llu %d died\n", time, philo->num_id);
    return ;
}


