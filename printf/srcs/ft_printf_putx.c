/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:50:44 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 11:03:14 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_putx_null(t_format *arg, int n)
{
	if (n == 0 && arg->hexa)
	{
		if (arg->width)
		{
			arg->hexa = 0;
			arg->width += 2;
		}
		else
			arg->hexa = 0;
	}
}

static void	ft_printf_putx_width_precis(t_format *arg, int n)
{
	size_t	nlen;

	nlen = ft_hexalen(n);
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
	ft_printf_putx_null(arg, n);
}

static int	ft_printf_putx_zero(t_format *arg, char *pref)
{
	int	res;

	res = 0;
	if (arg->zero && arg->hexa)
	{
		res += ft_putstr_fd(pref, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	else if (!arg->zero && arg->hexa)
	{
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
		res += ft_putstr_fd(pref, 1);
	}
	else
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	return (res);
}

static int	ft_printf_putx_put(t_format *arg, int n, char *base, char *pref)
{
	int		res;

	res = 0;
	if (arg->justify)
	{
		if (arg->hexa)
			res += ft_putstr_fd(pref, 1);
		res += ft_putnchar_fd('0', arg->precis, 1);
		if (n == 0 && arg->isprecis && arg->tmpprecis == 0)
			res += ft_putnchar_fd(' ', 1, 1);
		else
			res += ft_putu_base_fd((unsigned int)n, base, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	else
	{
		res += ft_printf_putx_zero(arg, pref);
		res += ft_putnchar_fd('0', arg->precis, 1);
		if (n == 0 && arg->isprecis && arg->tmpprecis == 0)
			res += ft_putnchar_fd(' ', 1, 1);
		else
			res += ft_putu_base_fd((unsigned int)n, base, 1);
	}
	return (res);
}

int	ft_printf_putx(va_list ap, t_format *arg, char *base, char *pref)
{
	int	res;
	int	va;

	res = 0;
	va = (int)va_arg(ap, int);
	ft_printf_putx_width_precis(arg, va);
	if (arg->width && arg->isprecis)
		arg->blank = ' ';
	if (va == 0 && arg->tmpwidth == 0 && arg->isprecis && arg->tmpprecis == 0)
		res += 0;
	else
		res += ft_printf_putx_put(arg, va, base, pref);
	return (res);
}
