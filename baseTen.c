/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseTen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:38:44 by takumi            #+#    #+#             */
/*   Updated: 2023/08/23 01:13:26 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_count(int number)
{
	long long	buffer;
	int			count;

	count = 0;
	buffer = number;
	if (number < 0)
	{
		count++;
		buffer *= -1;
	}
	while (buffer >= 10)
	{
		buffer /= 10;
		count++;
	}
	return (count + 1);
}

int	base_ten(int number)
{
	long long	buffer;

	buffer = number;
	if (buffer < 0)
	{
		base_c('-');
		buffer *= -1;
	}
	if (buffer / 10 == 0)
		base_c(buffer + '0');
	else
	{
		base_ten(buffer / 10);
		base_c(buffer % 10 + '0');
	}
	return (number_count(number));
}

static int	unsigned_number_count(unsigned int number)
{
	int	count;

	count = 0;
	while (number >= 10)
	{
		number /= 10;
		count++;
	}
	return (count + 1);
}

int	unsigned_base_ten(unsigned int number)
{
	if (number / 10 == 0)
		base_c(number + '0');
	else
	{
		base_ten(number / 10);
		base_c(number % 10 + '0');
	}
	return (unsigned_number_count(number));
}

// #include<stdio.h>
// int main()
// {
//     int count;
//     unsigned int number = 4294967295;
//     count = unsigned_base_ten(number);
//     printf("\n %d",count);
//     return (0);
// }