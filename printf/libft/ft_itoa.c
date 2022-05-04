/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:47:00 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/28 11:41:38 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_len_nbr(int n)
{
	size_t			res;
	unsigned int	un;

	res = 1;
	un = 0;
	if (n < 0)
	{
		un = -(unsigned int)n;
		res++;
	}
	else
		un = (unsigned int)n;
	while (un / 10 > 0)
	{
		un = un / 10;
		res++;
	}
	return (res);
}

static unsigned int	ft_int_unsigned_int(char *ptr, int n, int *index)
{
	unsigned int	res;

	res = 0;
	if (n < 0)
	{
		ptr[0] = '-';
		*index = *index + 1;
		res = -(unsigned int)n;
	}
	else
		res = (unsigned int)n;
	return (res);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	size_t			len_n;
	unsigned int	un;
	int				i;

	len_n = ft_len_nbr(n);
	ptr = (char *)malloc(sizeof(char) * (len_n + 1));
	if (!ptr)
		return (0);
	un = 0;
	i = 0;
	un = ft_int_unsigned_int(ptr, n, &i);
	ptr[len_n] = '\0';
	len_n--;
	while ((int)len_n >= i)
	{
		ptr[len_n] = un % 10 + '0';
		un /= 10;
		len_n--;
	}
	return (ptr);
}
