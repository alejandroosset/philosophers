/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:33:11 by aosset-o          #+#    #+#             */
/*   Updated: 2025/08/19 11:25:27 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int parse_error(int ac, char *av[])
{
    if (ac != 5 && ac != 6)
        return(-1);
    if(ft_atoi(av[1])<1)
        return(-1);
    if(ft_atoi(av[2])<60)
        return(-1);
    if(ft_atoi(av[3])<60)
        return(-1);
    if(ft_atoi(av[4])<60)
        return(-1);
    if(ac == 6)
    {
        if(ft_atoi(av[5])<1)
            return(-1);
    }  
    return(1);      
}