/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:59:35 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/26 16:29:56 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len_s;

	len_s = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!ptr)
	{
		return (0);
	}
	ft_memcpy(ptr, s1, len_s);
	ptr[len_s] = '\0';
	return (ptr);
}
