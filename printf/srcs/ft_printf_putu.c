/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:38:25 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 11:25:12 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_putu_width_precis(t_format *arg, unsigned int n)
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
	if (((int)nlen + arg->precis) >= arg->tmpwidth)
		arg->width = 0;
	else
		arg->width = arg->tmpwidth - ((int)nlen + arg->precis);
}

static int	ft_printf_putu_put(t_format *arg, unsigned int n, char *base)
{
	int		res;

	res = 0;
	if (arg->justify)
	{
		res += ft_putnchar_fd('0', arg->precis, 1);
		if (n == 0 && arg->isprecis && arg->tmpprecis == 0)
			res += ft_putnchar_fd(' ', 1, 1);
		else
			res += ft_putu_base_fd((unsigned long long)n, base, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	else
	{
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
		res += ft_putnchar_fd('0', arg->precis, 1);
		if (n == 0 && arg->isprecis && arg->tmpprecis == 0)
			res += ft_putnchar_fd(' ', 1, 1);
		else
			res += ft_putu_base_fd((unsigned long long)n, base, 1);
	}
	return (res);
}

int	ft_printf_putu(va_list ap, t_format *arg, char *base)
{
	int				res;
	unsigned int	va;

	res = 0;
	va = (unsigned int)va_arg(ap, unsigned int);
	ft_printf_putu_width_precis(arg, va);
	if (arg->width && arg->isprecis)
		arg->blank = ' ';
	if (va == 0 && arg->tmpwidth == 0 && arg->isprecis && arg->tmpprecis == 0)
		res += 0;
	else
		res += ft_printf_putu_put(arg, va, base);
	return (res);
}
