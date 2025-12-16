/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:06:46 by aosset-o          #+#    #+#             */
/*   Updated: 2025/12/16 17:44:00 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
int	case_one(t_data *data)
{
	messages("has taken a fork", data->philos);
	ft_usleep(data->death_time);
	messages("died", data->philos);
    ft_exit(data);
    return (0);
}
void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	int dead;
	pthread_mutex_lock(&philo->lock);
	philo->time_to_die = philo->data->death_time + get_current_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->lock);
	pthread_create(&philo->t1, NULL, &monitor, philo);
	/*if (philo->id % 2 == 1 && get_current_time() == 0)
        ft_usleep(500);*/
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
	pthread_join(philo->t1, NULL);
	return (NULL);
}
int main(int ac, char *av[])
{
	t_data data;
	
	if(init(ac, av, &data))
		return(1);
	if (data.philo_num == 1)
		return (case_one(&data));
	if(init_threads(&data))
		return(1);
	ft_exit(&data);
	return(0);		
}