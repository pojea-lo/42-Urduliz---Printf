/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:50:29 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/01/11 15:50:47 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
size_t	ft_cases(char s, va_list ptr, size_t j);
size_t	ft_putchar(char r, size_t j);
size_t	ft_putstr(char *r, size_t j);
size_t	ft_putptr(void *ptr, size_t j);
size_t	ft_putint(int n, size_t j);
size_t	ft_putuint(unsigned int n, size_t j);
size_t	ft_puthexmi(size_t n, size_t j);
size_t	ft_puthexma(size_t n, size_t j);
size_t	ft_strlen(char *s);
size_t	ft_hex(size_t n, char c, size_t j);
char	*ft_itoa(int n);
char	*ft_neg(int n);
char	*ft_pos(long int n);
int		ft_count(long int n);

#endif
