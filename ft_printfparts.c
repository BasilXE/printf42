/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfparts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 16:13:53 by basayoub          #+#    #+#             */
/*   Updated: 2026/10/25 16:13:53 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(int u)
{
	unsigned int n;
	char	m;
	int	count;

	count = 0; 
	n = (unsigned int)u;
	if (n > 9)
		count += ft_putnbr(n / 10);
	m = n % 10 + '0';
	count += write (1, &m, 1);
	return (count);
}

int	ft_putlowhexa(unsigned int x)
{
	char	*c;
	int	count;

	count = 0;
	c = "0123456789abcdef";
	if (x >= 16)
		count += ft_putlowhexa(x / 16);
	count += write (1, &c[x % 16], 1);
	return (count);
}

int	ft_putuphexa(unsigned int x)
{
	char		*c;
	int		count;

	count = 0;
	c = "0123456789ABCDEF";
	if (x >= 16)
		count += ft_putuphexa(x / 16);
	count += write (1, &c[x % 16], 1);
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(write(1, "(null)",6));
	while (str[i])
		i++;
	return (write(1, str, i));
}
