/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:54:25 by antho             #+#    #+#             */
/*   Updated: 2021/12/23 12:45:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnchar_fd(char c, int n, int fd)
{
	int	res;

	if (!fd)
		return (0);
	res = 0;
	while (n > 0)
	{
		write(fd, &c, (unsigned long)fd);
		n--;
		res++;
	}
	return (res);
}
