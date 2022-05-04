/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:53:50 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/26 14:09:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*res;
	int				i;

	res = (unsigned char *)s;
	i = 0;
	while (i < (int) n)
	{
		res[i] = (unsigned char)c;
		i++;
	}
	return (res);
}
