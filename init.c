/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:24:23 by aosset-o          #+#    #+#             */
/*   Updated: 2025/08/19 13:01:41 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void init_arg(int ac, char *av[], t_args *args)
{
    if (ac != 5 && ac != 6)
        return(-1);
    args->n_philosophers = ft_atoi(av[1]);
    args->time_to_die = ft_atoi(av[2]);
    args->time_to_eat = ft_atoi(av[3]);
    args->time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
    {
        args->num_time_philos_eat = ft_atoi(av[5]);
        if(args->num_time_philos_eat < 1)
            return(-1);
    }
    if(args->n_philosophers < 1 || args->time_to_die < 60 || args->time_to_eat < 60 || args->time_to_sleep < 60)
        return(-1);
    return(1);
}
