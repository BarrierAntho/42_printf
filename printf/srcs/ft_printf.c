/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:23:39 by abarrier          #+#    #+#             */
/*   Updated: 2022/01/03 14:43:09 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* target:
 * reproduce the function printf from libc
 * va-list can not get number of arguments, it must trustly done by the user

 * return:
 * 0 if it was correct
 * -1 if format malloc did not work
 * -2 if one of format sentence is wrong
 */

static int	ft_printf_final(const char *str, va_list ap, t_format **lstarg)
{
	t_format	*arg;
	int			res;
	int			i;

	arg = 0;
	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			arg = *lstarg;
			res += ft_printf_putformat(ap, arg);
			ft_printf_argdel_front(lstarg);
			i += arg->convpos + 1;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			res++;
			i++;
		}
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int			res;
	t_format	**lstarg;
	va_list		ap;

	res = 0;
	lstarg = (t_format **)malloc(sizeof(t_format *));
	if (!lstarg)
		return (-1);
	*lstarg = 0;
	if (ft_printf_lstformat(str, lstarg) <= 0)
		return (ft_putstr_fd((char *)str, 1));
	va_start(ap, str);
	res += ft_printf_final(str, ap, lstarg);
	ft_printf_argclear(lstarg, 0);
	va_end(ap);
	return (res);
}
