/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseP.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:03:35 by takumi            #+#    #+#             */
/*   Updated: 2023/08/23 01:03:38 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	unsigned_small_base_sixteen(uintptr_t number)
{
	if (number < 16)
		base_c("0123456789abcdef"[number]);
	else
	{
		unsigned_small_base_sixteen(number / 16);
		base_c("0123456789abcdef"[number % 16]);
	}
}

static int	unsigned_sixteen_number_count(uintptr_t number)
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

int	base_pointer(uintptr_t p)
{
	base_s("0x");
	unsigned_small_base_sixteen(p);
	return (unsigned_sixteen_number_count(p) + 2);
}

// #include <stdio.h>
// int main()
// {
//     int a = 0;
//     printf("%d\n",base_pointer(a));
//     printf("%p\n",&a);
//     return (0);
// }