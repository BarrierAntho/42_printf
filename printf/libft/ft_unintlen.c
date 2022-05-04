/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unintlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:52:16 by antho             #+#    #+#             */
/*   Updated: 2021/12/30 10:01:03 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Get length of unsigned integer. At minimum i = 1 because 0 <= n <= 9 */
size_t	ft_unintlen(unsigned long long n)
{
	size_t	i;

	i = 1;
	while (n / 10 > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
