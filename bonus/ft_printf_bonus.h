/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:02:05 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/01/14 06:35:40 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
void	ft_cases_flag(const char *s, va_list ptr, int *r);
size_t	ft_cases_type(char s, va_list ptr, size_t j);
size_t	ft_putchar(char r, size_t j);
size_t	ft_putstr(char *r, size_t j);
size_t	ft_putptr(void *ptr, size_t j);
size_t	ft_putint(int n, size_t j);
size_t	ft_putint_flag(int n, size_t j, size_t k);
size_t	ft_putuint(unsigned int n, size_t j);
size_t	ft_puthexmi(unsigned int n, size_t j);
size_t	ft_puthexmi_flag(unsigned int n, size_t j);
size_t	ft_puthexma(unsigned int n, size_t j);
size_t	ft_puthexma_flag(unsigned int n, size_t j);
size_t	ft_strlen(char *s);
size_t	ft_hex(unsigned int n, char c, size_t j);
char	*ft_itoa(int n);
char	*ft_itoa_b(int n, size_t k);
char	*ft_neg(int n);
char	*ft_pos(long int n);
char	*ft_pos_b(long int n, size_t k);
int		ft_count(long int n);

#endif
