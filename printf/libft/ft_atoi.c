/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:55:41 by abarrier          #+#    #+#             */
/*   Updated: 2021/12/10 10:37:27 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert a string to integer */
int	ft_atoi(const char *str)
{
	unsigned int	n;
	int				sign;
	unsigned int	i;

	n = 0;
	sign = 1;
	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		n = n * 10 + (unsigned int)(str[i] - '0');
		i++;
	}
	return (sign * (int)n);
}
