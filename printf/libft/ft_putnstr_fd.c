/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:23:31 by antho             #+#    #+#             */
/*   Updated: 2021/12/23 12:43:01 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr_fd(char *s, int n, int fd)
{
	int	res;
	int	i;

	if (!s || !fd)
		return (0);
	res = 0;
	i = 0;
	while (s[i] && n > 0)
	{
		res += ft_putchar_fd(s[i], fd);
		n--;
		i++;
	}
	return (res);
}
