/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_argadd_back.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:21:26 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 15:44:10 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* target:
 * add arg to the arg list
 * 
 * return:
 * N/A
 */
void	ft_printf_argadd_back(t_format **lst, t_format *new)
{
	t_format	*alst;

	if (!new)
		return ;
	ft_printf_purgeformat(new);
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	alst = *lst;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}
