/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:36:36 by antho             #+#    #+#             */
/*   Updated: 2021/12/29 09:49:48 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* target:
 * get the length of 
 */
size_t	ft_hexalen(int n)
{
	size_t			res;
	unsigned int	un;

	res = 1;
	un = (unsigned int)n;
	while (un >= 16)
	{
		un /= 16;
		res++;
	}
	return (res);
}
