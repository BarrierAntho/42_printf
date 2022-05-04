/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:33:11 by abarrier          #+#    #+#             */
/*   Updated: 2021/11/26 14:10:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > 0)
	{
		i++;
		n--;
	}
	if (n > 0)
	{
		return ((unsigned char)s1[i] - s2[i]);
	}
	else
	{
		return (0);
	}
}
