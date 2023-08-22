/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseTen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:38:44 by takumi            #+#    #+#             */
/*   Updated: 2023/08/22 23:59:54 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int NumberCount(int number)
{
    long long buffer;
    int count;
    count = 0;
    buffer = number;
    if(number < 0)
    {
        count++;
        buffer *= -1;
    }
    while (buffer >= 10)
    {
        buffer /= 10;
        count++;
    }
    return count + 1;
}

int baseTen(int number)
{
    long long buffer;
    buffer = number;
    if(buffer < 0)
    {
        baseC('-');
        buffer *= -1;
    }
    if(buffer / 10 == 0)
        baseC(buffer + '0');
    else 
    {
        baseTen(buffer/10);
        baseC(buffer % 10 + '0');
    }
    return (NumberCount(number));
}

static int UnsignedNumberCount(unsigned int number)
{
    int count;
    count = 0;
    while (number >= 10)
    {
        number /= 10;
        count++;
    }
    return count + 1;
}

int UnsignedBaseTen(unsigned int number)
{
    if(number / 10 == 0)
        baseC(number + '0');
    else 
    {
        baseTen(number/10);
        baseC(number % 10 + '0');
    }
    return (UnsignedNumberCount(number));
}

// #include<stdio.h>
// int main()
// {
//     int count;
//     unsigned int number = 4294967295;
//     count = UnsignedBaseTen(number);
//     printf("\n %d",count);
//     return 0;
// }