/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_purgeformat.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:37:22 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 15:14:47 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * according to the original printf :
 * flag ' ' is ignored when flag '+' is present
 * flag '0' is ignored when flag '-' is present
 * flag '+' results in undefined behavior with 'c' conversion specifier
 * flag '0' results in undefined behavior with 'c' conversion specifier
 * flag ' ' results in undefined behavior with 'c' conversion specifier
 * flag '#' results in undefined behavior with 'c' conversion specifier
 * precision used with 'c' conversion specifier, resulting in undefined
   behavior
 * flag '+' results in undefined behavior with 's' conversion specifier
 * flag '0' results in undefined behavior with 's' conversion specifier
 * flag ' ' results in undefined behavior with 's' conversion specifier
 * flag '#' results in undefined behavior with 's' conversion specifier
 * flag '+' results in undefined behavior with 'p' conversion specifier
 * flag '0' results in undefined behavior with 'p' conversion specifier
 * flag ' ' results in undefined behavior with 'p' conversion specifier
 * flag '#' results in undefined behavior with 'p' conversion specifier
 * precision used with 'p' conversion specifier, resulting in undefined
   behavior
 * flag '#' results in undefined behavior with 'd' conversion specifier
 * flag '#' results in undefined behavior with 'i' conversion specifier
 * flag '+' results in undefined behavior with 'u' conversion specifier
 * flag ' ' results in undefined behavior with 'u' conversion specifier
 * flag '#' results in undefined behavior with 'u' conversion specifier
 * flag '+' results in undefined behavior with 'x' conversion specifier
 * flag ' ' results in undefined behavior with 'x' conversion specifier
 * personnal remarks
 * width is ignored when it is less or equal than precision
 * if conversion is '%', all flags are valid excepted precision
 */

/* set to zero some arg format property no matters of the conversion */
static void	ft_printf_format_commonrules(t_format *arg)
{
	if (arg->plus)
		arg->sign = '+';
	if (arg->space)
		arg->sign = ' ';
	if (arg->plus && arg->space)
	{
		arg->space = 0;
		arg->sign = '+';
	}
	if (arg->zero)
		arg->blank = '0';
	if (arg->justify && arg->zero)
	{
		arg->zero = 0;
		arg->blank = ' ';
	}
}

void	ft_printf_purgeformat(t_format *arg)
{
	ft_printf_format_commonrules(arg);
	if (arg->conv == 'c')
	{
		arg->isprecis = 0;
		arg->tmpprecis = 0;
	}
	if (arg->conv == 'c' || arg->conv == 's' || arg->conv == 'p')
	{
		arg->plus = 0;
		arg->zero = 0;
		arg->space = 0;
	}
	if (arg->hexa && !(arg->conv == 'x' || arg->conv == 'X'))
		arg->hexa = 0;
	if (arg->conv == 'p')
		arg->hexa = 1;
	if (arg->conv == 'u' || arg->conv == 'x' || arg->conv == 'X')
	{
		arg->plus = 0;
		arg->space = 0;
	}
}
