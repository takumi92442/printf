/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:04:52 by takumi            #+#    #+#             */
/*   Updated: 2023/08/23 00:23:31 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_printf_support(const char c, va_list *ap)
{
    if(c == 'c')
        return (baseC(va_arg(*ap,int)));
    if(c == 's')
        return (baseS(va_arg(*ap,char*)));
    if(c == 'p')
        return (basePointer(va_arg(*ap,uintptr_t)));
    if(c == 'd')
        return (baseTen(va_arg(*ap,int)));
    if(c == 'i')
        return (baseTen(va_arg(*ap,int)));
    if(c == 'u')
        return (UnsignedBaseTen(va_arg(*ap,unsigned int)));
    if(c == 'x')
        return (SmallBaseSixteen(va_arg(*ap,unsigned int)));
    if(c == 'X')
        return (BigBaseSixteen(va_arg(*ap,unsigned int)));
    if(c == '%')
        return (Persent());
    return 0;
}

int  ft_printf(const char *fmt, ...)
{
    va_list ap;
    int count;

    count = 0;
    va_start(ap, fmt);
    while (*fmt)
    {
        if(*fmt == '%')
        {
            fmt++;
            count += ft_printf_support(*fmt, &ap);
        }
        else
            count += baseC(*fmt);
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
    
//     return 0;
// }