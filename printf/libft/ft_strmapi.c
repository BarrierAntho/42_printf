/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:17:37 by antho             #+#    #+#             */
/*   Updated: 2021/11/28 17:48:11 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	size_t			len_s;
	unsigned int	i;

	if (!s || !f)
		return (0);
	len_s = ft_strlen(s);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
