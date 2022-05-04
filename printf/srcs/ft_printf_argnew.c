/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_argnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:14:31 by antho             #+#    #+#             */
/*   Updated: 2021/12/31 11:23:00 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* target:
 * create new arg and set to zero each format property
 *
 * return:
 * adress of the new arg
 */
t_format	*ft_printf_argnew(void)
{
	t_format	*new;

	new = (t_format *)malloc(sizeof(t_format));
	if (!new)
		return (0);
	new->plus = 0;
	new->justify = 0;
	new->zero = 0;
	new->space = 0;
	new->hexa = 0;
	new->tmpwidth = 0;
	new->width = 0;
	new->isprecis = 0;
	new->tmpprecis = 0;
	new->precis = 0;
	new->conv = 0;
	new->convpos = 0;
	new->blank = ' ';
	new->sign = 0;
	new->next = 0;
	return (new);
}
