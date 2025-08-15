/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:33:11 by aosset-o          #+#    #+#             */
/*   Updated: 2025/08/15 13:54:34 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int parce_error(int ac, char *av[])
{
    if (ac != 5 || av != 6)
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
        if(ft_atoi(av[1])<1)
            return(-1);
    }         
}