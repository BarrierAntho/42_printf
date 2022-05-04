/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:52 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/04 08:32:16 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ucdest;
	unsigned char	*ucsrc;

	ucdest = (unsigned char *)dest;
	ucsrc = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (ucdest >= ucsrc)
	{
		while (n != '\0')
		{
			n--;
			ucdest[n] = ucsrc[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (ucdest);
}
