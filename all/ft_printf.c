/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:46:22 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/01/14 16:54:59 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list		ptr;
	int			r[2];

	r[0] = 0;
	r[1] = 0;
	va_start (ptr, s);
	while (s[r[0]] != '\0')
	{	
		if (s[r[0]] == '%' && s[r[0]])
		{
			r[0] = r[0] + 1;
			ft_cases_flag(s, ptr, r);
		}
		else
		{
			write (1, &s[r[0]], 1);
			r[0] = r[0] + 1;
			r[1] = r[1] + 1;
		}
	}
	va_end (ptr);
	return (r[1]);
}

void	ft_cases_flag(const char *s, va_list ptr, int *r)
{
	size_t	k;

	k = 0;
	if (s[r[0]] == '+' || s[r[0]] == ' ' || s[r[0]] == '#')
	{
		if (s[r[0]] == ' ')
			k = 1;
		while (s[r[0]] == '+' || s[r[0]] == ' ' || s[r[0]] == '#')
			r[0]++;
		if (s[r[0]] == 'd' || s[r[0]] == 'i')
			r[1] = ft_putint_flag (va_arg (ptr, int), r[1], k);
		else if (s[r[0]] == 'x')
			r[1] = ft_puthexmi_flag(va_arg (ptr, int), r[1]);
		else if (s[r[0]] == 'X')
			r[1] = ft_puthexma_flag(va_arg (ptr, int), r[1]);
		else
			r[1] = ft_cases_type(s[r[0]], ptr, r[1]);
	}
	else
		r[1] = ft_cases_type(s[r[0]], ptr, r[1]);
	r[0]++;
}

size_t	ft_cases_type(char s, va_list ptr, size_t j)
{
	if (s == 'c')
		j = ft_putchar (va_arg (ptr, int), j);
	else if (s == 's')
		j = ft_putstr (va_arg (ptr, char *), j);
	else if (s == 'p')
		j = ft_putptr (va_arg (ptr, size_t), j);
	else if (s == 'd')
		j = ft_putint (va_arg (ptr, int), j);
	else if (s == 'i')
		j = ft_putint (va_arg (ptr, int), j);
	else if (s == 'u')
		j = ft_putuint (va_arg (ptr, unsigned int), j);
	else if (s == 'x')
		j = ft_puthexmi (va_arg (ptr, unsigned int), j);
	else if (s == 'X')
		j = ft_puthexma (va_arg (ptr, unsigned int), j);
	else if (s == '%')
	{
		write (1, "%", 1);
		j++;
	}
	return (j);
}
