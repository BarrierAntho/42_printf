/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:36:43 by abarrier          #+#    #+#             */
/*   Updated: 2021/12/23 12:45:36 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	res;
	int	i;

	if (!s || !fd)
		return (0);
	res = 0;
	i = 0;
	while (s[i])
	{
		res += ft_putchar_fd(s[i], fd);
		i++;
	}
	return (res);
}
