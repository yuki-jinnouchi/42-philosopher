/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:11:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/07/11 12:21:30 by yjinnouc         ###   ########.fr       */
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
