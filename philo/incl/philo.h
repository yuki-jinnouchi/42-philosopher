/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjinnouc <yjinnouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:55:11 by yjinnouc          #+#    #+#             */
/*   Updated: 2024/04/16 17:40:09 by yjinnouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define FAILURE -1

# define TRUE 1
# define FALSE 0

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <stdio.h> // size_t, NULL, printf, perror
# include <unistd.h> // write, usleep
# include <stdint.h> // uint64_t
# include <stdlib.h> // malloc, free
# include <string.h> // memset
# include <sys/time.h> // gettimeofday
// pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>
# include <errno.h>
// # include "libft.h"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				num_id;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				eat_count;
	uint64_t		last_eat;
	pthread_mutex_t	last_eat_mutex;
	pthread_mutex_t	dead_mutex;
	int				dead;
	pthread_mutex_t	finished_mutex;
	int				finished;
	// uint64_t		time_to_die;
	// uint64_t		time_to_eat;
	// uint64_t		time_to_sleep;
	// int				max_time_eat;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_time_eat;
	uint64_t		start_time;
	pthread_t		*thread_ids;
	struct s_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finished_mutex;
	int				finished;
}	t_data;

//main.c
int			main(int argc, char **argv);

//init_data.c
int			philo_atoi(const char *nptr);
int			init_data_args(int argc, char **argv, t_data *data);
int			init_data_malloc(t_data *data);

//init_threads.c
int			init_philos_forks(t_data *data, t_philo *philo, int i);
int			init_philos(t_data *data);
int			init_forks(t_data *data);
int			init_threads(t_data *data);

//exec.c
int			exec(t_data *data);

//thread_observer.c
uint64_t	get_last_eat(t_philo *philo);
int			if_someone_dead(t_data *data);
int			if_everyone_finish(t_data *data);
void		finish_everyone(t_data *data);
void		*observer(void *val);

//thread_philos.c
int			philosopher_take_left_fork(t_philo *philo);
int			philosopher_take_right_fork(t_philo *philo);
int			philosopher_sleep(t_philo *philo);
int			philosopher_eat(t_philo *philo);
void		*philosopher(void *val);

//utils.c
uint64_t	get_current_time(void);
uint64_t	get_time_from_start(t_data *data);
uint64_t	get_time_from_last_eat(t_philo *philo, t_data *data);
void		msleep(uint64_t time);

int			is_philo_starving(t_philo *philo, t_data *data);

int			if_philo_dead(t_philo *philo);
int			if_philo_finished(t_philo *philo);
int			if_all_finished(t_data *data);

//free.c
void		free_data(t_data *data);

//error.c
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		exit_wo_perror(char *message1, t_data *data);

#endif
