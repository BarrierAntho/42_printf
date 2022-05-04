/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:44:16 by antho             #+#    #+#             */
/*   Updated: 2021/12/06 09:04:03 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_start_end_trim(const char *str, char const *charset, int sign)
{
	int	i;

	if (sign > 0)
	{
		i = 0;
		while (str[i] && ft_strchr(charset, str[i]))
			i++;
	}
	else
	{
		i = (int)ft_strlen(str) - 1;
		while (str[i] && ft_strchr(charset, str[i]))
			i--;
	}
	if (sign > 0 && str[i] == '\0')
		return (-1);
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*ptr;
	size_t		len_s;
	int			i_start;
	int			i_end;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	i_start = ft_start_end_trim(s1, set, 1);
	if (i_start == -1)
	{
		ptr = (char *)malloc(sizeof(char));
		if (!ptr)
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	i_end = ft_start_end_trim(s1, set, -1);
	len_s = (size_t)(i_end - i_start + 1);
	ptr = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, &s1[i_start], (size_t)(len_s + 1));
	return (ptr);
}
