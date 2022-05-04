/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antho <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:21:20 by antho             #+#    #+#             */
/*   Updated: 2022/01/03 15:43:33 by abarrier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_format
{
	int					plus;
	int					justify;
	int					zero;
	int					space;
	int					hexa;
	int					tmpwidth;
	int					width;
	int					isprecis;
	int					tmpprecis;
	int					precis;
	char				conv;
	int					convpos;
	char				blank;
	int					issign;
	char				sign;
	struct s_format		*next;
}						t_format;

int			ft_printf(const char *str, ...);
int			ft_printf_lstformat(const char *str, t_format **lstarg);
int			ft_printf_getformat(const char *str, t_format *arg);
void		ft_printf_purgeformat(t_format *arg);

t_format	*ft_printf_argnew(void);
void		ft_printf_argadd_back(t_format **lst, t_format *new);
void		ft_printf_argdel_front(t_format **lst);
void		ft_printf_argclear(t_format **lst, t_format *arg);

int			ft_printf_putformat(va_list ap, t_format *arg);
int			ft_printf_putc(va_list ap, t_format *arg);
int			ft_printf_puts(va_list ap, t_format *arg);
int			ft_printf_putd(va_list ap, t_format *arg, char *base);
int			ft_printf_putp(va_list ap, t_format *arg, char *base);
int			ft_printf_putu(va_list ap, t_format *arg, char *base);
int			ft_printf_putx(va_list ap, t_format *arg, char *base, char *pref);
int			ft_printf_putper(t_format *arg);

#endif
