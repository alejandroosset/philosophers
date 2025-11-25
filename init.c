/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:24:23 by aosset-o          #+#    #+#             */
/*   Updated: 2025/11/25 19:19:25 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void alloc_structure(t_data *data)
{
    data->tid = malloc(sizeof(pthread_t) * data->philo_num);
    if(!data->tid)
        return(ft_putendl_fd("Error de maalloc",2), NULL);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
    if(!data->forks)
        return(ft_putendl_fd("Error de maalloc",2), NULL);
    data->philos = malloc(sizeof(t_philo) * data->philo_num);
    if(!data->philos)
        return(ft_putendl_fd("Error de maalloc",2), NULL);
}   
void init_data(int ac, char *av[], t_data *data)
{
    data->philo_num = ft_atoi(av[1]);
    data->death_time = ft_atoi(av[2]);
    data->eat_time = ft_atoi(av[3]);
    data->sleep_time = ft_atoi(av[4]);
    if(ac == 6)
        data->meals_nb = ft_atoi(av[5]);
    else 
        data->meals_nb = -1;
    data->dead = 0;
    data->finished = 0;
    pthread_mutex_init(&data->lock, NULL);
    pthread_mutex_init(&data->write, NULL);
}
void init_forks()
