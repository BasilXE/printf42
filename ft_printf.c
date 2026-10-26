/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 23:30:51 by basayoub          #+#    #+#             */
/*   Updated: 2026/10/27 02:34:54 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	char h;

	h = (char)c;
	write (1, &h, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	char	m;
	int count;

	count = 0;
	if (n == -2147483648)
	{
		return(write (1, "-2147483648", 11));
	}
	if (n < 0)
	{
		count += write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
		 count += ft_putnbr(n / 10);
	m = n % 10 + '0';
	 count += write (1, &m, 1);
	return (count);
}
int	elser(size_t i, const char *f, int count)
{
	write(1, &f[i], 1);
	count++;
	i++;
	return (count);
}
int	iffer(size_t i, va_list	bob, const char *f, int count)
{
	while (f[i])
	{
		if (f[i] == '%' && f[i + 1] == 'c' && ++i)
			count += ft_putchar(va_arg(bob, int));
		else if (f[i] == '%' && f[i + 1] == 's' && ++i)
			count += ft_putstr(va_arg(bob, char *));
		else if (f[i] == '%' && (f[i + 1] == 'd' || f[i + 1] == 'i') && ++i)
			count += ft_putnbr(va_arg(bob, int));
		else if (f[i] == '%' && f[i + 1] == 'u' && ++i)
			count += ft_putunsigned(va_arg(bob, int));
		else if (f[i] == '%' && f[i + 1] == '%' && ++i)
			count += write (1, "%", 1);
		else if (f[i] == '%' && f[i + 1] == 'p' && ++i)
			count += ft_putvoid(va_arg(bob, void *));
		else if (f[i] == '%' && f[i + 1] == 'x' && ++i)
			count += ft_putlowhexa(va_arg(bob, unsigned int));
		else if (f[i] == '%' && f[i + 1] == 'X' && ++i)
			count += ft_putuphexa(va_arg(bob, unsigned int)); 
		else if (f[i] == '%')
			i++;
		else
			count = elser(i,f,count);
		i++;
    }
	return (count);
}
int	ft_printf(const char *f, ...)
{
    size_t	i;
    va_list	bob;

    i = 0;
    va_start(bob,f);
    i = iffer(i,bob,f,0);
    va_end(bob);
    return ((int)i);
}
/*int main()
{
	void *a = "17";
//	char *u = "th";
//	printf("/%d\\\n",ft_printf(" %p ",a));
//	printf("+%d+",printf(" %p ",a));
	printf("--%d--",ft_printf("the world\nputchar : %c\nputstr : %s\nputnumber : (i) %i \t(d) %d\nunsigned : %u\nthe :%%\npointer : %p\nlow hexa : %x\nUP HEXA : %X",'k',"str love ",-42,42,163,a,-148,-148));
	printf("==%d==",printf("\n\nthe world\nputchar : %c\nputstr : %s\nputnumber : (i) %i \t(d) %d\nunsigned : %u\nthe :%%\npointer : %p\nlow hexa : %x\nUP HEXA : %X",'k',"str love ",-42,42,163,a,-148,-148)-2);
}*/
