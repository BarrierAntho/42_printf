/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puti_base_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 09:33:26 by antho             #+#    #+#             */
/*   Updated: 2021/12/30 09:33:37 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_puti_base_fd(long long n, const char *base, int fd)
{
	int					res;
	size_t				len_base;
	unsigned long long	un;

	res = 0;
	len_base = ft_strlen(base);
	un = 0;
	if (*base != 0 && len_base > 1 && ft_check_base(base) == 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			un = -(unsigned long long)n;
		}
		else
			un = (unsigned long long)n;
		ft_putn_rfd(un, base, fd, &res);
	}
	return (res);
}
