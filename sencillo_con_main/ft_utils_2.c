/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:51:11 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/01/14 12:19:19 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexmi(unsigned int n, size_t j)
{
	if (n == 0)
	{
		write (1, "0", 1);
		j = j + 1;
	}
	else
		j = ft_hex (n, 'x', j);
	return (j);
}

size_t	ft_puthexma(unsigned int n, size_t j)
{
	if (n == 0)
	{
		write (1, "0", 1);
		j = j + 1;
	}
	else
		j = ft_hex (n, 'X', j);
	return (j);
}

size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	if (s == NULL)
		return (0);
	while (s[l] != '\0')
		l++;
	return (l);
}

size_t	ft_hex(size_t n, char c, size_t j)
{
	char	*hexmi;
	char	*hexma;

	hexmi = "0123456789abcdef";
	hexma = "0123456789ABCDEF";
	if (n > 0)
	{
		if (c == 'X')
		{
			j = ft_hex (n / 16, c, j);
			j = j + 1;
			write (1, &hexma [n % 16], 1);
		}
		else
		{
			j = ft_hex (n / 16, c, j);
			j = j + 1;
			write (1, &hexmi [n % 16], 1);
		}
	}
	return (j);
}
