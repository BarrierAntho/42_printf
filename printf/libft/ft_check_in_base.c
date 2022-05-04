/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_in_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:03:49 by antho             #+#    #+#             */
/*   Updated: 2021/12/18 22:00:27 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check if the char is present in the base */
int	ft_check_in_base(const char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
