/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_base_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 09:35:33 by antho             #+#    #+#             */
/*   Updated: 2021/12/30 09:35:37 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_putu_base_fd(unsigned long long n, const char *base, int fd)
{
	int					res;
	size_t				len_base;

	res = 0;
	len_base = ft_strlen(base);
	if (*base != 0 && len_base > 1 && ft_check_base(base) == 0)
		ft_putn_rfd(n, base, fd, &res);
	return (res);
}
