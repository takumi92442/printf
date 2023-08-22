/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseP.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:03:35 by takumi            #+#    #+#             */
/*   Updated: 2023/08/23 00:39:55 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void  UnsignedSmallBaseSixteen(uintptr_t number)
{
    if(number < 16)
        baseC("0123456789abcdef"[number]);
    else
    {
        UnsignedSmallBaseSixteen(number / 16);
        baseC("0123456789abcdef"[number % 16]);   
    }
}

static int UnsignedSixteenNumberCount(uintptr_t number)
{
    int count;
    count = 0;
    while (number >= 16)
    {
        number /= 16;
        count++;
    }
    return count + 1;
}

int basePointer(uintptr_t p)
{
    baseS("0x");
    UnsignedSmallBaseSixteen(p);
    return (UnsignedSixteenNumberCount(p) + 2);
}

// #include <stdio.h>
// int main()
// {
//     int a = 0;
//     printf("%d\n",basePointer(a));
//     printf("%p\n",&a);
//     return 0;
// }