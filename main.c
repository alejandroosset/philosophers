/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:06:46 by aosset-o          #+#    #+#             */
/*   Updated: 2025/11/28 17:20:14 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	if (!philo)
		return (NULL);
	eat(philo);
    sleeping(philo);
    think(philo);
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