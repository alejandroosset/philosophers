/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:09:58 by aosset-o          #+#    #+#             */
/*   Updated: 2025/08/15 13:33:58 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_args
{
   int n_philosophers;
   int time_to_die;
   int time_to_eat;
   int time_to_sleep;
   int				num_time_philos_eat;
}t_args;

typedef struct s_philo
{
	int nb_philo;
   int time_death;
   int time_eat;
   int time_sleep;
   int nb_eat;
   int dead;
}					t_philo;
int	ft_atoi(const char *nptr);
void  init_arg(int ac, char *av[], t_args *args);
#endif