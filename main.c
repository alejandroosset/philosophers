/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:06:46 by aosset-o          #+#    #+#             */
/*   Updated: 2025/08/19 11:24:23 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine()
{
	printf("Test from threads\n");
	sleep(5);
	printf("Ending thread\n");
	return(NULL);
}
int main(int ac, char *av[])
{
	printf("%i\n",ft_atoi(av[1]));
	if(parse_error(ac, av) == -1)
		return(ft_putendl_fd("Invalid arguments", 2), 1);
	return(0);
		
}