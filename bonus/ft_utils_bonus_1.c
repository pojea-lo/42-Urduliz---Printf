/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pojea-lo <pojea-lo@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:04:36 by pojea-lo          #+#    #+#             */
/*   Updated: 2022/01/12 11:03:20 by pojea-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_putchar(char r, size_t j)
{
	write (1, &r, 1);
	j = j + 1;
	return (j);
}

size_t	ft_putstr(char *r, size_t j)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen (r);
	if (r == NULL)
	{
		write (1, "(null)", 6);
		j = j + 6;
		return (j);
	}
	while (i < l)
	{
		write (1, &r[i], 1);
		i++;
		j++;
	}
	return (j);
}

size_t	ft_putptr(void *ptr, size_t j)
{
	size_t	n;

	n = (size_t) ptr;
	write (1, "0x", 2);
	if (n == 0)
	{
		write (1, "0", 1);
		j = j + 3;
	}
	else
		j = 2 + ft_hex (n, 'p', j);
	return (j);
}

size_t	ft_putint(int n, size_t j)
{
	size_t	i;
	char	*r;

	i = 0;
	r = ft_itoa (n);
	while (i < ft_strlen (r))
	{
		write (1, &r[i], 1);
		i++;
		j = j + 1;
	}
	free (r);
	return (j);
}

size_t	ft_putuint(unsigned int n, size_t j)
{
	size_t	i;
	char	*r;

	i = 0;
	r = ft_pos (n);
	while (i < ft_strlen (r))
	{
		write (1, &r[i], 1);
		i++;
		j = j + 1;
	}
	free (r);
	return (j);
}
