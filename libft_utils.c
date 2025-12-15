/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:33:18 by aosset-o          #+#    #+#             */
/*   Updated: 2025/12/15 11:23:49 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	dif;
	int	i;

	i = 0;
	dif = 0;
	while ((s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			dif = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (dif);
		}
		i++;
	}
	return (dif);
}

long	ft_atoi(const char *nptr)
{
	int	i;
	long	res;

	i = 0;
	res = 0;
	while (nptr[i] != '\0')
	{
		if (((nptr[i]<= '0' && nptr[i] >= '9')) &&  nptr[i] != '+' && 
			(nptr[i] >= 9 && nptr[i] <= 13))
			return(-1);
		i++;
	}
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	if(nptr[i] != '\0')
		return(-1);
	return (res);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}