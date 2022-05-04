/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:43:11 by antho             #+#    #+#             */
/*   Updated: 2021/12/30 10:45:52 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* target:
 * get the length of
 */
size_t	ft_pointerlen(unsigned long long n)
{
	size_t			res;

	res = 1;
	while (n >= 16)
	{
		n /= 16;
		res++;
	}
	return (res);
}
