/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:50:47 by abarrier          #+#    #+#             */
/*   Updated: 2021/12/30 10:44:29 by antho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);

int			ft_toupper(int c);
int			ft_tolower(int c);

void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);

int			ft_atoi(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);

void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

int			ft_putchar_fd(char c, int fd);
int			ft_putnchar_fd(char c, int n, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnstr_fd(char *s, int n, int fd);
void		ft_putendl_fd(char *s, int fd);

/* Additional functions */
size_t		ft_intlen(int n);
size_t		ft_unintlen(unsigned long long n);
size_t		ft_hexalen(int n);
size_t		ft_pointerlen(unsigned long long n);
int			ft_check_base(const char *base);
int			ft_check_in_base(const char c, const char *base);
long long	ft_atoi_base(const char *str, const char *base);
int			ft_puti_base_fd(long long int n, const char *base, int fd);
int			ft_putu_base_fd(unsigned long long int n, const char *base, int fd);
void		ft_putn_rfd(unsigned long long n, const char *base, int fd, int *i);

#endif
