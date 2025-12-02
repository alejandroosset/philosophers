/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 16:19:47 by aosset-o          #+#    #+#             */
/*   Updated: 2025/12/02 17:24:03 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void take_forks(t_philo *philo)
{
    if(philo->id % 2 == 0)
    {   
        pthread_mutex_lock(philo->r_fork);
        messages("has taken a fork", philo);
        pthread_mutex_lock(philo->l_fork);
        messages("has taken a fork", philo);
    }
    else
    {
        pthread_mutex_lock(philo->l_fork);
        messages("has taken a fork", philo);
        pthread_mutex_lock(philo->r_fork);
        messages("has taken a fork", philo); 
    }

}
void eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->lock);
    messages("is eating", philo);
    philo->time_to_die = get_current_time() + philo->data->death_time - philo->data->start_time;
    philo->eat_count++;
    philo->eating = 1;
    ft_usleep(philo->data->eat_time);
    philo->eating = 0;
    pthread_mutex_unlock(&philo->lock);
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}