/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_argdel_front.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 06:27:09 by antho             #+#    #+#             */
/*   Updated: 2021/12/30 11:18:44 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_argdel_front(t_format **lst)
{
	t_format	*alst;
	t_format	*dlst;

	if (!lst)
		return ;
	if (!*lst)
		return ;
	alst = *lst;
	if (!alst->next)
	{
		free(alst);
		*lst = 0;
	}
	else
	{
		dlst = alst;
		alst = alst->next;
		free(dlst);
		dlst = 0;
		*lst = alst;
	}
}
