/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:31:50 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 16:58:20 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (s == NULL)
		return ;
	while (s[count] != '\0')
	{
		ft_putchar_fd(s[count], fd);
		count++;
	}
	return ;
}

/*copy and edit from pipex*/
void	exit_wo_perror(char *message, t_data *data)
{
	ft_putstr_fd("philo: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	if (data != NULL)
		free_data(data);
	exit(EXIT_FAILURE);
}
