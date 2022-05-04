/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putformat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 06:12:23 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 13:26:11 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putformat(va_list ap, t_format *arg)
{
	int				res;

	res = 0;
	if (arg->conv == 'c')
		res += ft_printf_putc(ap, arg);
	else if (arg->conv == 's')
		res += ft_printf_puts(ap, arg);
	else if (arg->conv == 'p')
		res += ft_printf_putp(ap, arg, "0123456789abcdef");
	else if (arg->conv == 'd' || arg->conv == 'i')
		res += ft_printf_putd(ap, arg, "0123456789");
	else if (arg->conv == 'u')
		res += ft_printf_putu(ap, arg, "0123456789");
	else if (arg->conv == 'x')
		res += ft_printf_putx(ap, arg, "0123456789abcdef", "0x");
	else if (arg->conv == 'X')
		res += ft_printf_putx(ap, arg, "0123456789ABCDEF", "0X");
	else if (arg->conv == '%')
		res += ft_printf_putper(arg);
	else
		res += 0;
	return (res);
}
