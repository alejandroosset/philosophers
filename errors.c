/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:08:00 by aosset-o          #+#    #+#             */
/*   Updated: 2025/08/21 15:30:19 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_args(int ac, char *av[])
{
	if(ac != 5 && ac != 6)
		return(ft_putendl_fd("Number of arguments is invalid", 2), -1);
	if(ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200 || ft_atoi(av[2]) < 60 || 
	ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return(ft_putendl_fd("The value of the arguments is invalid ", 2), -1);
	if (ac == 6)
	{
		if(ft_atoi(av[5]) < 60)
			return(ft_putendl_fd("The value of the arguments is invalid ", 2), -1);
	}
	return(1);
}