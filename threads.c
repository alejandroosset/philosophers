/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:05:24 by aosset-o          #+#    #+#             */
/*   Updated: 2025/11/27 16:56:34 by aosset-o         ###   ########.fr       */
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