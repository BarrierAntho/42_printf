/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 20:54:20 by antho             #+#    #+#             */
/*   Updated: 2021/12/18 22:00:06 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Check if the base does not have duplicate char or forbidden char */
int	ft_check_base(const char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j)
			{
				if (base[i] == base[j] || base[i] == '-' || base[i] == '+')
					return (1);
				else if (base[i] < 33 || base[i] == 127)
					return (2);
			}
			j++;
		}
		i++;
	}
	return (0);
}
