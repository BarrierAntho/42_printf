/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lstformat.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:43:58 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 14:32:13 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* target:
 * populate the list of arg format
 *
 * return:
 * <=0 if the arg format is wrong
 * >0 if the arg format is corret
 */
int	ft_printf_lstformat(const char *str, t_format **lstarg)
{
	t_format	*arg;
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			arg = ft_printf_argnew();
			if (!arg)
				return (0);
			i++;
			i += ft_printf_getformat(&str[i], arg);
			ft_printf_argadd_back(lstarg, arg);
		}
		else
			i++;
	}
	return (i);
}
