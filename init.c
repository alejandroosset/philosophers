/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:24:23 by aosset-o          #+#    #+#             */
/*   Updated: 2025/12/17 16:49:53 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
int alloc_structure(t_data *data)
{
    data->tid = malloc(sizeof(pthread_t) * data->philo_num);
    if(!data->tid)
        return(ft_putendl_fd("Malloc error",2), 1);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
    if(!data->forks)
        return(ft_putendl_fd("Malloc error",2), 1);
    data->philos = malloc(sizeof(t_philo) * data->philo_num);
    if(!data->philos)
        return(ft_putendl_fd("Malloc error",2), 1);
    return(0);
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
    data->start_time = get_current_time();
    pthread_mutex_init(&data->lock, NULL);
    pthread_mutex_init(&data->write, NULL);
}
void init_forks(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_num)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    data->philos[0].l_fork = &data->forks[0];
    data->philos[0].r_fork = &data->forks[data->philo_num - 1];
    i = 1;
    while (i < data->philo_num)
    {
        data->philos[i].l_fork = &data->forks[i];
        data->philos[i].r_fork = &data->forks[i - 1];
        i++;
    }
}
void init_philos(t_data *data)
{
    int i;

    i = 0;
    while(i < data->philo_num)
    {
        data->philos[i].id = i + 1;
        data->philos[i].eat_count = 0;
        data->philos[i].status = 0;
        data->philos[i].eating = 0;
        data->philos[i].time_to_die = data->death_time;
        pthread_mutex_init(&data->philos[i].lock, NULL);
        data->philos[i].data = data;
        i++;
    }
}
int init(int ac, char *av[], t_data *data)
{
    if(check_args(ac, av))
        return(1);
    init_data(ac, av, data);
    if(alloc_structure(data))
        return(1);
    init_forks(data);
    init_philos(data);
    return(0);
}
