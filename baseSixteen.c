/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseSixteen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 01:31:22 by takumi            #+#    #+#             */
/*   Updated: 2023/08/22 01:58:07 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int SixteenNumberCount(unsigned int number)
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

int  BigBaseSixteen(unsigned int number)
{
    if(number < 16)
        baseC("0123456789ABCDEF"[number]);
    else
    {
        BigBaseSixteen(number / 16);
        baseC("0123456789ABCDEF"[number % 16]);   
    }
    return (SixteenNumberCount(number));
}

int  SmallBaseSixteen(unsigned int number)
{
    if(number < 16)
        baseC("0123456789abcdef"[number]);
    else
    {
        SmallBaseSixteen(number / 16);
        baseC("0123456789abcdef"[number % 16]);   
    }
    return (SixteenNumberCount(number));
}
#include<stdio.h>
int main()
{
    int number;
    number = 255;
    int count;
    count = SmallBaseSixteen(number);
    printf("\n %d",count);
}