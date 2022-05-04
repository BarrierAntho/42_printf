/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:58:12 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 11:25:02 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_puts_width(t_format *arg, char *str)
{
	if (arg->isprecis)
	{
		if ((int)ft_strlen(str) <= arg->tmpprecis)
			arg->tmpprecis = (int)ft_strlen(str);
		return (arg->tmpwidth - arg->tmpprecis);
	}
	else
		return (arg->tmpwidth - (int)ft_strlen(str));
}

static int	ft_printf_puts_precis(t_format *arg, char *str)
{
	if (arg->isprecis)
	{
		if ((int)ft_strlen(str) <= arg->tmpprecis)
			return ((int)ft_strlen(str));
		else
			return (arg->tmpprecis);
	}
	else
		return ((int)ft_strlen(str));
}

static int	ft_printf_puts_put(t_format *arg, char *str)
{
	int		res;

	res = 0;
	if (arg->justify)
	{
		res += ft_putnstr_fd(str, arg->precis, 1);
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
	}
	else
	{
		res += ft_putnchar_fd(arg->blank, arg->width, 1);
		res += ft_putnstr_fd(str, arg->precis, 1);
	}
	return (res);
}

int	ft_printf_puts(va_list ap, t_format *arg)
{
	int		res;
	char	*va;

	res = 0;
	va = (char *)va_arg(ap, char *);
	if (!va)
	{
		arg->width = ft_printf_puts_width(arg, "(null)");
		arg->precis = ft_printf_puts_precis(arg, "(null)");
		res = ft_printf_puts_put(arg, "(null)");
	}
	else
	{
		arg->width = ft_printf_puts_width(arg, va);
		arg->precis = ft_printf_puts_precis(arg, va);
		res = ft_printf_puts_put(arg, va);
	}
	return (res);
}
