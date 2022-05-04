/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:50:06 by antho             #+#    #+#             */
/*   Updated: 2021/12/28 15:29:39 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Convert a string to integer according to a base*/
static long long int	ft_strlen_atoi_base(const char *str)
{
	long long int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

long long int	ft_atoi_base(const char *str, const char *base)
{
	long long int	n;
	long long int	sign;
	int				i;

	n = 0;
	sign = 1;
	if (ft_strlen_atoi_base(base) > 1 && ft_check_base(base) == 0)
	{
		i = 0;
		while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		while (str[i] && ft_check_in_base(str[i], base) >= 0)
		{
			n = n * ft_strlen_atoi_base(base) + str[i] - (long long int) '0';
			i++;
		}
	}
	return (sign * n);
}
