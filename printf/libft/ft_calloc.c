/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:31:15 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/26 16:29:47 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (char *)malloc(sizeof(char) * (count * size));
	if (!ptr)
	{
		return (0);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}
