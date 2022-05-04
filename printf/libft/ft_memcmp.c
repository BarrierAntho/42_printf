/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:00:18 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/26 14:08:29 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;
	int				i;

	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	i = 0;
	while (i < (int) n)
	{
		if (ucs1[i] != ucs2[i])
		{
			return ((unsigned char)ucs1[i] - ucs2[i]);
		}
		i++;
	}
	return (0);
}
