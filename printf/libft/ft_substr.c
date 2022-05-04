/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:27:07 by abarrier          #+#    #+#             */
/*   Updated: 2022/05/04 08:33:11 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len > len_s)
		len = len_s;
	if (start >= len_s)
		len = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !ptr)
		return (0);
	ft_memset(ptr, '\0', len + 1);
	ft_memmove(ptr, s + start, len);
	return (ptr);
}
