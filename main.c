/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:06:46 by aosset-o          #+#    #+#             */
/*   Updated: 2025/12/03 17:41:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	int dead;
	pthread_mutex_lock(&philo->lock);
	philo->time_to_die = philo->data->death_time + get_current_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->lock);
	pthread_create(&philo->t1, NULL, &monitor, philo);
	dead = 0;
	while (dead == 0)
	{
		take_forks(philo);
		eat(philo);
    	messages("is sleeping", philo);
    	ft_usleep(philo->data->sleep_time);
    	messages("is thinking", philo);
		dead = is_dead(philo);
	}
	if(pthread_join(philo->t1, NULL))
		return((void *) 1);
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