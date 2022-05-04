/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:18:21 by abarrier          #+#    #+#             */
/*   Updated: 2022/01/03 13:39:51 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_putper_width_precis(t_format *arg)
{
	size_t	clen;

	clen = 1;
	if (arg->isprecis)
	{
		if ((int)clen >= arg->tmpprecis)
			arg->precis = 0;
		else
			arg->precis = arg->tmpprecis - (int)clen;
	}
	else
		arg->precis = 0;
	if (arg->sign)
		clen++;
	if (((int)clen + arg->precis) >= arg->tmpwidth)
		arg->width = 0;
	else
		arg->width = arg->tmpwidth - ((int)clen + arg->precis);
}

static int	ft_printf_putper_sign(t_format *arg)
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

static int	ft_printf_putper_put(t_format *arg, char c)
{
	int		res;

	res = 0;
	if (arg->justify)
	{
		if (arg->sign)
			res += ft_putnchar_fd(arg->sign, 1, 1);
		res += ft_putnchar_fd('0', arg->precis, 1);
		res += ft_putnchar_fd(c, 1, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	else
	{
		res += ft_printf_putper_sign(arg);
		res += ft_putnchar_fd('0', arg->precis, 1);
		res += ft_putnchar_fd(c, 1, 1);
	}
	return (res);
}

int	ft_printf_putper(t_format *arg)
{
	int				res;
	char			va;

	res = 0;
	va = '%';
	ft_printf_putper_width_precis(arg);
	if (arg->width && arg->isprecis)
		arg->blank = ' ';
	if (va == 0 && arg->tmpwidth == 0 && arg->isprecis && arg->tmpprecis == 0)
		res += 0;
	else
		res += ft_printf_putper_put(arg, va);
	return (res);
}
