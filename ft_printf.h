/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basayoub <basayoub@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 23:32:34 by basayoub          #+#    #+#             */
/*   Updated: 2026/10/25 22:10:25 by basayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_putnbr(int n, size_t i);
size_t	ft_putstr(char *str, size_t j);
size_t	ft_putchar(int c, size_t i);
void	iffer(size_t i, va_list	bob, const char *f);
int ft_printf(const char *f, ...);
size_t	ft_putunsigned(int u, size_t i);
size_t	ft_putvoid(void *p, size_t i);
size_t	ft_putlowhexa(unsigned int x, size_t q);
size_t	ft_putuphexa(unsigned int x, size_t q);


#endif