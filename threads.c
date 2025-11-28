/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:05:24 by aosset-o          #+#    #+#             */
/*   Updated: 2025/11/28 17:14:21 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_threads(t_data *data)
{
    int i;
    
    i = -1;
    data->start_time = get_current_time();
    while(i++<data->philo_num - 1)
    {
        if (pthread_create(&data->tid[i], NULL, routine, &data->philos[i]))
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
    if(philo->data->dead == 0 && ft_strcmp(str, "died") == 0)
    {
        printf("%zu %i %s\n", time, philo->id, str);
        philo->data->dead = 1;
    }
    if(!philo->data->dead)
       printf("%zu %i %s\n", time, philo->id, str);
    pthread_mutex_unlock(&philo->data->write);
}