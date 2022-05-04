/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_argclear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:22:26 by antho             #+#    #+#             */
/*   Updated: 2021/12/31 11:22:45 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* target:
 * free the arg non allocated to the arg list and free whole arg format
 * allocated arg from the arg list and free the arg list itself
 *
 * return:
 * N/A
 */
void	ft_printf_argclear(t_format **lst, t_format *arg)
{
	t_format	*alst;
	t_format	*dlst;

	if (arg)
	{
		free(arg);
		arg = 0;
	}
	if (*lst)
	{
		alst = *lst;
		while (alst->next)
		{
			dlst = alst;
			alst = alst->next;
			free(dlst);
			dlst = 0;
		}
		free(alst);
		alst = 0;
	}
	free(lst);
	lst = 0;
}
