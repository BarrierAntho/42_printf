/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:45:45 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 11:05:51 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_putd_width_precis(t_format *arg, unsigned int n)
{
	size_t	nlen;

	nlen = ft_unintlen(n);
	if (arg->isprecis)
	{
		if ((int)nlen >= arg->tmpprecis)
			arg->precis = 0;
		else
			arg->precis = arg->tmpprecis - (int)nlen;
	}
	else
		arg->precis = 0;
	if (arg->sign)
		nlen++;
	if (((int)nlen + arg->precis) >= arg->tmpwidth)
		arg->width = 0;
	else
		arg->width = arg->tmpwidth - ((int)nlen + arg->precis);
}

static int	ft_printf_putd_sign(t_format *arg)
{
	int	res;

	res = 0;
	if (arg->zero && arg->tmpwidth && !arg->tmpprecis)
	{
		if (arg->sign)
			res += ft_putnchar_fd(arg->sign, 1, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	else if (arg->tmpwidth || arg->tmpprecis)
	{
		res += ft_putnchar_fd(' ', arg->width, 1);
		if (arg->sign)
			res += ft_putnchar_fd(arg->sign, 1, 1);
	}
	else
	{
		if (arg->sign)
			res += ft_putnchar_fd(arg->sign, 1, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	return (res);
}

static int	ft_printf_putd_put(t_format *arg, unsigned int n, char *base)
{
	int		res;

	res = 0;
	if (arg->justify)
	{
		if (arg->sign)
			res += ft_putnchar_fd(arg->sign, 1, 1);
		res += ft_putnchar_fd('0', arg->precis, 1);
		if (n == 0 && arg->isprecis && arg->tmpprecis == 0)
			res += ft_putnchar_fd(' ', 1, 1);
		else
			res += ft_putu_base_fd(n, base, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	else
	{
		res += ft_printf_putd_sign(arg);
		res += ft_putnchar_fd('0', arg->precis, 1);
		if (n == 0 && arg->isprecis && arg->tmpprecis == 0)
			res += ft_putnchar_fd(' ', 1, 1);
		else
			res += ft_putu_base_fd(n, base, 1);
	}
	return (res);
}

int	ft_printf_putd(va_list ap, t_format *arg, char *base)
{
	int				res;
	int				va;
	unsigned int	uva;

	res = 0;
	va = (int)va_arg(ap, int);
	if (va < 0)
	{
		arg->sign = '-';
		uva = -(unsigned int)va;
	}
	else
		uva = (unsigned int)va;
	ft_printf_putd_width_precis(arg, uva);
	if (arg->width && arg->isprecis)
		arg->blank = ' ';
	if (va == 0 && arg->tmpwidth == 0 && arg->isprecis && arg->tmpprecis == 0)
		res += 0;
	else
		res += ft_printf_putd_put(arg, uva, base);
	return (res);
}
