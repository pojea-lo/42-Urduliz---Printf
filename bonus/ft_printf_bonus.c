/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:46:22 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/01/14 12:55:17 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
/*
int	main(void)
{
	char	*s;
	int		j = 0;

	s = "%p";
	printf ("\n***ft_printf done:\n");
	j = ft_printf(s, LONG_MIN);
	printf(", y la j = %d\n", j);
	j = ft_printf(s, LONG_MAX);
	printf(", y la j = %d\n", j);
	j = ft_printf(s, ULONG_MAX);
	printf(", y la j = %d\n", j);
	j = ft_printf(s, -ULONG_MAX);
	printf(", y la j = %d\n", j);
//	j = ft_printf(s, "565424");
//	printf(", y la j = %d\n", j);
	

	printf ("\n\n***printf done:\n");
	j = printf ("%p", LONG_MIN);
	printf(", y la j = %d\n", j);
	j = printf ("%p", LONG_MAX);
	printf(", y la j = %d\n", j);
	j = printf ("%p", ULONG_MAX);
	printf(", y la j = %d\n", j);
	j = printf ("%p", -ULONG_MAX);
	printf(", y la j = %d\n", j);
	printf ("\n\n***printf done:\n");
	printf ("Resultado printf con flag '+' pos:	%# x\n", 534534);
	printf ("Resultado printf con flag '+' neg:	%+d\n", -2);
	printf ("Resultado printf con flag 'alineado':	%8d\n", 2);
	printf ("Resultado printf con flag '0': 		%08d\n", -2);
	printf ("Resultado printf con flag '.': 		%.8d\n", -2);
	printf ("Resultado printf con flag '-': 		%-8d\n", 2);
	printf ("Resultado printf con flag ' ':		% d\n", 2);
	printf ("Resultado printf con flag ' ':		% d\n", -2);
	printf ("Resultado printf con flag ' ':		% s\n", "20");
	printf ("Resultado printf con flag '#' Hex:	%#X\n", 55642);
	return (0);
}*/

int	ft_printf(const char *s, ...)
{
	size_t		i;
	size_t		j;
	va_list		ptr;
	int			r[2];

	i = 0;
	j = 0;
	va_start (ptr, s);
	while (s[i] != '\0')
	{	
		if (s[i] == '%' && s[i])
		{
			i++;
			r[0] = i;
			r[1] = j;
			ft_cases_flag(s, ptr, r);
			i = r[0];
			j = r[1];
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

void	ft_cases_flag(const char *s, va_list ptr, int *r)
{
	size_t	k;
	size_t	i;
	size_t	j;

	i = r[0];
	j = r[1];
	if (s[i] == '+')
	{
		k = 0;
		i++;
		if (s[i] == 'd' || s[i] == 'i')
		{
			j = ft_putint_flag (va_arg (ptr, int), j, k);
			i++;
		}
		else
		{
			j = ft_cases_type(s[i], ptr, j);
			i++;
		}
	}
	else if (s[i] == ' ')	
	{
		k = 1;
		i++;
		if (s[i] == 'd' || s[i] == 'i')
		{
			j = ft_putint_flag (va_arg (ptr, int), j, k);
			i++;
		}
		else
		{
			j = ft_cases_type(s[i], ptr, j);
			i++;
		}
	}
	else if (s[i] == '#')
	{
		i++;
		if (s[i] == 'x')
		{
			j = ft_puthexmi_flag(va_arg (ptr, int), j);
			i++;
		}
		else if (s[i] == 'X')
		{
			j = ft_puthexma_flag(va_arg (ptr, int), j);
			i++;
		}
		else
		{
			j = ft_cases_type(s[i], ptr, j);
			i++;
		}
	}
	else
	{
		j = ft_cases_type(s[i], ptr, j);
		i++;
	}
	r[0] = i;
	r[1] = j;
}


size_t	ft_cases_type(char s, va_list ptr, size_t j)
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
		j++;
	}
	else
		write (1, "ERROR", 5);
	return (j);
}
