/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:09:58 by aosset-o          #+#    #+#             */
/*   Updated: 2025/12/03 17:20:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t       t1;
	int             id;
	int             eat_count;
	int             status;
	int             eating;
	size_t        time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
} t_philo;

typedef struct s_data
{
	pthread_t       *tid;
	int             philo_num;
	int             meals_nb;
	int             dead;
	int             finished;
	t_philo         *philos;
	size_t       death_time;
	size_t       eat_time;
	size_t       sleep_time;
	size_t       start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
	pthread_mutex_t write;
} t_data;
size_t	ft_atoi(const char *nptr);
int  init_arg(int ac, char *av[], t_philo *philo);
int check_args(int ac, char *av[]);
void	ft_putendl_fd(char *s, int fd);
int	ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
void *routine(void *arg);
int init(int ac, char *av[], t_data *data);
int init_threads(t_data *data);
int	ft_strcmp(const char *s1, const char *s2);
void ft_exit(t_data *data);
void messages(char *str, t_philo *philo);
void take_forks(t_philo *philo);
void eat(t_philo *philo);
void *supervisor(void *data_pointer);
void *monitor(void *philo_pointer);
int is_dead(t_philo *philo);
#endif