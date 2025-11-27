/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:06:46 by aosset-o          #+#    #+#             */
/*   Updated: 2025/11/27 17:55:54 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	printf("filosofo %d: empezando\n", philo->id);
	/* simple demonstration routine - in real program you'd implement thinking/eating/sleeping */
	ft_usleep(50);
	printf("filosofo %d: terminando\n", philo->id);
	return (NULL);
}
int main(int ac, char *av[])
{
	t_data data;
	
	if(init(ac, av, &data))
		return(1);
	if(init_threads(&data))
		return(1);
	ft_exit(&data);
	return(0);		
}