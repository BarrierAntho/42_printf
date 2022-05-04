/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getformat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:01:49 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 14:27:03 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* target:
 * get format definition from the string and apply value to arg format
 * properties
 *
 * return:
 * the offset of the readed string and afterwards be able to continue reading
 * the string at the end of this method
 */

static int	ft_printf_flags(const char *str, t_format *arg)
{
	int	i;

	i = 0;
	while (ft_strchr("+-0 #", str[i]))
	{
		if (str[i] == '+')
			arg->plus = 1;
		else if (str[i] == '-')
			arg->justify = 1;
		else if (str[i] == '0')
			arg->zero = 1;
		else if (str[i] == ' ')
			arg->space = 1;
		else if (str[i] == '#')
			arg->hexa = 1;
		i++;
	}
	return (i);
}

static int	ft_printf_width(const char *str, t_format *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[i]))
	{
		arg->tmpwidth = ft_atoi(str);
		i += ft_intlen(arg->tmpwidth);
	}
	return (i);
}

static int	ft_printf_precision(const char *str, t_format *arg)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		arg->isprecis = 1;
		i++;
		while (str[i] == '0')
			i++;
		if (ft_isdigit(str[i]))
		{
			arg->tmpprecis = ft_atoi(&str[i]);
			i += ft_intlen(arg->tmpprecis);
		}
		else
		{
			if (ft_strchr("cspdiuxX%", str[i]))
				arg->tmpprecis = 0;
			else
				arg->tmpprecis = -1;
		}
	}
	return (i);
}

static int	ft_printf_conversion(const char *str, t_format *arg)
{
	int	i;

	i = 0;
	if (ft_strchr("cspdiuxX%", str[i]))
	{
		arg->conv = str[i];
		i++;
	}
	else
		arg->conv = 'n';
	return (i);
}

int	ft_printf_getformat(const char *str, t_format *arg)
{
	int	i;

	i = 0;
	i += ft_printf_flags(&str[i], arg);
	i += ft_printf_width(&str[i], arg);
	i += ft_printf_precision(&str[i], arg);
	i += ft_printf_conversion(&str[i], arg);
	arg->convpos = i;
	if (arg->tmpprecis < 0)
		arg->conv = 'n';
	return (i);
}
