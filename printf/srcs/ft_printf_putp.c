/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 09:49:57 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 15:41:45 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_putp_width_precis(t_format *arg, unsigned long long n)
{
	size_t	nlen;

	nlen = ft_pointerlen(n);
	if (arg->isprecis)
	{
		if ((int)nlen >= arg->tmpprecis)
			arg->precis = 0;
		else
			arg->precis = arg->tmpprecis - (int)nlen;
	}
	else
		arg->precis = 0;
	if (arg->hexa)
		nlen += 2;
	if (((int)nlen + arg->precis) >= arg->tmpwidth)
		arg->width = 0;
	else
		arg->width = arg->tmpwidth - ((int)nlen + arg->precis);
}

static int	ft_printf_putp_put(t_format *arg, unsigned long long n, char *base)
{
	int		res;

	res = 0;
	if (arg->justify)
	{
		res += ft_putstr_fd("0x", 1);
		res += ft_putnchar_fd('0', arg->precis, 1);
		res += ft_putu_base_fd(n, base, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	else
	{
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
		res += ft_putstr_fd("0x", 1);
		res += ft_putnchar_fd('0', arg->precis, 1);
		res += ft_putu_base_fd(n, base, 1);
	}
	return (res);
}

int	ft_printf_putp(va_list ap, t_format *arg, char *base)
{
	int					res;
	unsigned long long	va;

	res = 0;
	va = (unsigned long long)va_arg(ap, void *);
	ft_printf_putp_width_precis(arg, va);
	res += ft_printf_putp_put(arg, va, base);
	return (res);
}
