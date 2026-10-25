/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 23:30:51 by basayoub          #+#    #+#             */
/*   Updated: 2026/10/25 23:16:07 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(int c, size_t i)
{
	char h;

	h = (char)c;
	write (1, &h, 1);
	return (++i);
}

size_t	ft_putstr(char *str, size_t j)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (++j);
}
size_t	ft_putnbr(int n, size_t i)
{
	char	m;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (++i);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, i);
	m = n % 10 + '0';
	write (1, &m, 1);
	i++;
	return (i);
}

void	iffer(size_t i, va_list	bob, const char *f)
{
	while (f[i])
	{
		if (f[i] == '%' && f[i + 1] == 'c')
			i = ft_putchar(va_arg(bob, int), i);
		else if (f[i] == '%' && f[i + 1] == 's')
			i = ft_putstr(va_arg(bob, char *), i);
		else if (f[i] == '%' && (f[i + 1] == 'd' || f[i + 1] == 'i'))
			i = ft_putnbr(va_arg(bob, int), i);
		else if (f[i] == '%' && f[i + 1] == 'u')
			i = ft_putunsigned(va_arg(bob, int), i);
		else if (f[i] == '%' && f[i + 1] == '%' && ++i)
			write (1, "%", 1);	
		else if (f[i] == '%' && f[i + 1] == 'p')
			i = ft_putvoid(va_arg(bob, void *), i);
		else if (f[i] == '%' && f[i + 1] == 'x')
			i = ft_putlowhexa(va_arg(bob, unsigned int), i);
		else if (f[i] == '%' && f[i + 1] == 'X')
			i = ft_putuphexa(va_arg(bob, unsigned int), i);
		else
			write (1, &f[i], 1);
		i++;
    	}
}

int	ft_printf(const char *f, ...)
{
    size_t	i;
    va_list	bob;

    i = 0;
    va_start(bob,f);
    iffer(i,bob,f);
    va_end(bob);
    return (i);
}
/*int main()
{
	char *u = "th";
	ft_printf("the world\nputchar : %c\nputstr : %s\nputnumber : (i) %i \t(d) %d\nunsigned : %u\nthe :%%\npointer : %p\nlow hexa : %x\nUP HEXA : %X",'k',"str love ",-42,42,163,u,-148,-148);
	printf("\n** %p **\n", u);
}*/
