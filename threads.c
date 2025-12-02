/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:05:24 by aosset-o          #+#    #+#             */
/*   Updated: 2025/12/02 18:00:03 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void *supervisor(void *data_pointer)
{
    t_philo *philo = (t_philo *)data_pointer;
    while (philo->data->dead == 0)
    {
        
        if(philo->data->finished >= philo->data->philo_num)
        {
            pthread_mutex_lock(&philo->data->lock);
            philo->data->dead = 1;
            pthread_mutex_unlock(&philo->data->lock);  
        }
        ft_usleep(100);
    }
    return((void *)0);
}
void *monitor(void *philo_pointer)
{
    t_philo *philo;

    philo = philo_pointer;
    while (philo->data->dead == 0)
    {
        if ((get_current_time() - philo->data->start_time) >= philo->time_to_die && philo->eating==0)
            messages("died", philo);
        if(philo->eat_count == philo->data->meals_nb)
        {
            pthread_mutex_lock(&philo->data->lock);
            philo->data->finished++;
            pthread_mutex_unlock(&philo->data->lock);
            pthread_mutex_lock(&philo->lock);
            philo->eat_count++;
            pthread_mutex_unlock(&philo->lock);
        }
        ft_usleep(100);
    }
    return((void *)0);
}
int init_threads(t_data *data)
{
    int i;
    pthread_t t0;
    
    i = -1;
    data->start_time = get_current_time();
    if(data->meals_nb > 0)
        pthread_create(&t0, NULL, &supervisor, &data->philos[0]);
    while(i++<data->philo_num - 1)
    {
        if (pthread_create(&data->tid[i], NULL, &routine, &data->philos[i]))
            return (ft_putendl_fd("Thread creating error", 2), 1);
    }
    i = -1;
    while (i++ < data->philo_num - 1)
        pthread_join(data->tid[i], NULL);
    return(0);
}

void messages(char *str, t_philo *philo)
{
    size_t time;

    time = get_current_time() - philo->data->start_time;
    pthread_mutex_lock(&philo->data->write);
    if(philo->eating == 0 && ft_strcmp(str, "died") == 0)
    {
        printf("%zu %i %s\n", time, philo->id, str);
        philo->data->dead = 1;
    }
    if(!philo->data->dead)
       printf("%zu %i %s\n", time, philo->id, str);
    pthread_mutex_unlock(&philo->data->write);
}