/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:04:52 by takumi            #+#    #+#             */
/*   Updated: 2023/08/23 01:13:26 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_support(const char c, va_list *ap)
{
	if (c == 'c')
		return (base_c(va_arg(*ap, int)));
	if (c == 's')
		return (base_s(va_arg(*ap, char *)));
	if (c == 'p')
		return (base_pointer(va_arg(*ap, uintptr_t)));
	if (c == 'd')
		return (base_ten(va_arg(*ap, int)));
	if (c == 'i')
		return (base_ten(va_arg(*ap, int)));
	if (c == 'u')
		return (unsigned_base_ten(va_arg(*ap, unsigned int)));
	if (c == 'x')
		return (smallbase_sixteen(va_arg(*ap, unsigned int)));
	if (c == 'X')
		return (big_base_sixteen(va_arg(*ap, unsigned int)));
	if (c == '%')
		return (persent());
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			count += ft_printf_support(*fmt, &ap);
		}
		else
			count += base_c(*fmt);
		fmt++;
	}
	va_end(ap);
	return (count);
}

// #include<stdio.h>
// int main()
// {
//     int a;
//     int b = 10;
//     a = ft_printf("hello %s",NULL);
//     // printf("asdfgh %s",NULL);

//     return (0);
// }