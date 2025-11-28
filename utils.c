/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:14:18 by aosset-o          #+#    #+#             */
/*   Updated: 2025/11/28 14:12:49 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_args(int ac, char *av[])
{
	if(ac != 5 && ac != 6)
		return(ft_putendl_fd("Number of arguments is invalid", 2), 1);
	if(ft_atoi(av[1]) < 1 || ft_atoi(av[2]) < 1 || 
	ft_atoi(av[3]) < 1 || ft_atoi(av[4]) < 1)
		return(ft_putendl_fd("The value of the arguments is invalid ", 2), 1);
	if (ac == 6)
	{
		if(ft_atoi(av[5]) < 1)
			return(ft_putendl_fd("The value of the arguments is invalid ", 2), 1);
	}
	return(0);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
void	clear_data(t_data	*data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}
void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putendl_fd("gettimeofday() error",2);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}