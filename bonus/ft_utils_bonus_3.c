#include "ft_printf_bonus.h"

size_t ft_putint_flag(int n, size_t j, size_t k)
{
	size_t	i;
	char	*r;

	i = 0;
	r = ft_itoa_b(n, k);
	while (i < ft_strlen (r))
	{
		write (1, &r[i], 1);
		i++;
		j = j + 1;
	}
	free (r);
	return (j);
}

char	*ft_itoa_b(int n, size_t k)
{
	if (n < 0 && n >= -2147483648)
		return (ft_neg(n));
	else
		return (ft_pos_b(n, k));
}

char	*ft_pos_b(long int n, size_t k)
{
	char	*r;
	int		i;
	char	c;

	i = ft_count(n) + 1;
	r = (char *)malloc (sizeof (char) * (ft_count(n) + 2));
	if (r == NULL)
		return (NULL);
	r[i] = '\0';
	i--;
	while (i >= 0)
	{
		c = (n % 10) + '0';
		r[i--] = c;
		n = n / 10;
	}
	if (k == 0)
		r[0] = '+';
	else
		r[0] = ' ';
	return (r);
}

size_t	ft_puthexmi_flag(unsigned int n, size_t j)
{
	if (n == 0)
	{
		write (1, "0", 1);
		j = j + 1;
	}
	else
	{
		write (1, "0x", 2);
		j = ft_hex (n, 'x', j) + 2;
	}
	return (j);
}

size_t	ft_puthexma_flag(unsigned int n, size_t j)
{
	if (n == 0)
	{
		write (1, "0", 1);
		j = j + 1;
	}
	else
	{
		write (1, "0X", 2);
		j = ft_hex (n, 'X', j) + 2;
	}
	return (j);
}
