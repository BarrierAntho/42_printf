/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:16:24 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/26 17:24:04 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int	rcmp;

	if (*to_find == 0)
	{
		return ((char *)str);
	}	
	i = 0;
	rcmp = 0;
	while (str[i] && len > 0)
	{
		if (ft_strlen(to_find) > len)
		{
			return (0);
		}
		rcmp = ft_strncmp(&str[i], to_find, ft_strlen(to_find));
		if (rcmp == 0)
		{
			return ((char *)&str[i]);
		}
		i++;
		len--;
	}
	return (0);
}
