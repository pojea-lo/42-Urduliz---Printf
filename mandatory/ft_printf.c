/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:46:22 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/01/11 15:48:21 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	size_t		i;
	size_t		j;
	va_list		ptr;

	i = 0;
	j = 0;
	va_start (ptr, s);
	while (s[i] != '\0')
	{	
		if (s[i] == '%' && s[i])
		{
			i++;
			j = ft_cases (s[i], ptr, j);
			i++;
		}
		else
		{
			write (1, &s[i], 1);
			i++;
			j++;
		}
	}
	va_end (ptr);
	return (j);
}

size_t	ft_cases(char s, va_list ptr, size_t j)
{
	if (s == 'c')
		j = ft_putchar (va_arg (ptr, int), j);
	else if (s == 's')
		j = ft_putstr (va_arg (ptr, char *), j);
	else if (s == 'p')
		j = ft_putptr (va_arg (ptr, void *), j);
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
		j = j + 1;
	}
	else
		write (1, "ERROR", 5);
	return (j);
}
