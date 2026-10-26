/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfpart2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 02:17:33 by basayoub          #+#    #+#             */
/*   Updated: 2026/10/27 02:35:51 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoidhexa(unsigned long x)
{
	char	*c;
	int	count;

	count = 0;
	c = "0123456789abcdef";
	if (x >= 16)
		count += ft_putvoidhexa(x / 16);
	count += write (1, &c[x % 16], 1);
	return (count);
}

int	ft_putvoid(void *p)
{
	unsigned long x;
	int	count;

    x = (unsigned long)p;
    if (x == 0)
        return (write(1, "(nil)",5));
    else
	    count = write (1, "0x", 2);
	count += ft_putvoidhexa(x);
	return (count);
}