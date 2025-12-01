/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:06:46 by aosset-o          #+#    #+#             */
/*   Updated: 2025/12/01 18:09:56 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	philo->time_to_die = philo->data->death_time + get_current_time() - philo->data->start_time;
	pthread_create(&philo->t1, NULL, &monitor, philo);
	while (philo->data->dead == 0)
	{
		eat(philo);
    	messages("is sleeping", philo);
    	ft_usleep(philo->data->sleep_time);
    	messages("is thinking", philo);
	}
	if(pthread_join(philo->t1, NULL))
		return((void *) 1);
	return ((void *) 1);
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