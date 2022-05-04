/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:17:08 by antho             #+#    #+#             */
/*   Updated: 2021/12/31 11:23:35 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putc(va_list ap, t_format *arg)
{
	int		res;
	char	va;

	res = 0;
	va = (char)va_arg(ap, int);
	arg->width = arg->tmpwidth;
	if (arg->justify)
	{
		res += ft_putchar_fd(va, 1);
		res += ft_putnchar_fd(arg->blank, arg->width - 1, 1);
	}
	else
	{
		res += ft_putnchar_fd(arg->blank, arg->width - 1, 1);
		res += ft_putchar_fd(va, 1);
	}
	return (res);
}
