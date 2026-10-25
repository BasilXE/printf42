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

size_t	ft_putunsigned(int u, size_t i)
{
	unsigned int n;
	char	m;
	
	n = (unsigned int)u;
	if (n > 9)
		ft_putnbr(n / 10, i);
	m = n % 10 + '0';
	write (1, &m, 1);
	i++;
	return (i);
}

size_t	ft_putlowhexa(unsigned int x, size_t q)
{
	char		*c;
	size_t		i;

	c = "0123456789abcdef";
	if (x >= 16)
		i = ft_putlowhexa(x / 16, q);
	write (1, &c[x % 16], 1);
	return (++q);
}

size_t	ft_putuphexa(unsigned int x, size_t q)
{
	char		*c;
	size_t		i;

	c = "0123456789ABCDEF";
	if (x >= 16)
		i = ft_putuphexa(x / 16, q);
	write (1, &c[x % 16], 1);
	return (++q);
}

size_t	ft_putvoid(void *x, size_t q)
{
	char		*c;
	size_t		i;

	write (1, "0x", 2);
	c = "0123456789abcdef";
	if ((unsigned long)x >= 16)
		i = ft_putlowhexa((unsigned long)x / 16, q);
	write (1, &c[(unsigned long)x % 16], 1);
	return (++q);
}
