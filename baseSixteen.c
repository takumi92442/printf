/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseSixteen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 01:08:18 by takumi            #+#    #+#             */
/*   Updated: 2023/08/23 01:10:21 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sixteen_number_count(unsigned int number)
{
	int	count;

	count = 0;
	while (number >= 16)
	{
		number /= 16;
		count++;
	}
	return (count + 1);
}

int	big_base_sixteen(unsigned int number)
{
	if (number < 16)
		base_c("0123456789ABCDEF"[number]);
	else
	{
		big_base_sixteen(number / 16);
		base_c("0123456789ABCDEF"[number % 16]);
	}
	return (sixteen_number_count(number));
}

int	smallbase_sixteen(unsigned int number)
{
	if (number < 16)
		base_c("0123456789abcdef"[number]);
	else
	{
		smallbase_sixteen(number / 16);
		base_c("0123456789abcdef"[number % 16]);
	}
	return (sixteen_number_count(number));
}

// #include<stdio.h>
// int main()
// {
//     int number;
//     number = 255;
//     int count;
//     count = smallbase_sixteen(number);
//     printf("\n %d",count);
// }