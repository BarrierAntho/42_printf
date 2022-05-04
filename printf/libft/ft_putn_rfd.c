/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn_rfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 09:19:39 by antho             #+#    #+#             */
/*   Updated: 2021/12/30 09:24:56 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* target:
 * put number recursively
 *
 * return:
 * return total of put number via int *i
 */
void	ft_putn_rfd(unsigned long long n, const char *base, int fd, int *i)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	if (n / len_base < 1)
		*i += ft_putchar_fd(base[n % len_base], fd);
	else
	{
		ft_putn_rfd(n / len_base, base, fd, i);
		ft_putn_rfd(n % len_base, base, fd, i);
	}
}
