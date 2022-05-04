/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:23:46 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/27 12:12:36 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize <= len_dest)
	{
		return (dstsize + len_src);
	}
	i = 0;
	j = len_dest;
	while (i < (dstsize - len_dest - 1) && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len_dest + len_src);
}
