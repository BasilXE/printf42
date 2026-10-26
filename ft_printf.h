/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 23:32:34 by basayoub          #+#    #+#             */
/*   Updated: 2026/10/27 02:23:46 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putvoidhexa(unsigned long x);
int	iffer(size_t i, va_list	bob, const char *f, int count);
int ft_printf(const char *f, ...);
int	ft_putunsigned(int u);
int	ft_putvoid(void *p);
int	ft_putlowhexa(unsigned int x);
int	ft_putuphexa(unsigned int x);


#endif