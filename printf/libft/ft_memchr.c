/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:29:21 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/26 14:08:22 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ucs;
	int				i;

	ucs = (unsigned char *)s;
	i = 0;
	while (i < (int) n)
	{
		if (*ucs == (unsigned char)c)
		{
			return (ucs);
		}
		ucs++;
		i++;
	}
	return (0);
}
