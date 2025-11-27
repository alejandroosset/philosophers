/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:06:46 by aosset-o          #+#    #+#             */
/*   Updated: 2025/11/26 16:47:40 by marvin           ###   ########.fr       */
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
	if(check_args(ac, av))
		return(1);
	return(0);		
}