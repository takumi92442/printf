/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseSC.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 01:06:01 by takumi            #+#    #+#             */
/*   Updated: 2023/08/23 01:07:47 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_c(char C)
{
	return (write(1, &C, 1));
}

int	ft_strlen(const char *S)
{
	int	count;

	count = 0;
	while (*S != '\0')
	{
		count++;
		S++;
	}
	return (count);
}

int	base_s(const char *S)
{
	int	count;

	if (S == NULL)
		return (write(1, "(null)", 6));
	count = ft_strlen(S);
	return (write(1, S, count));
}

int	persent(void)
{
	return (write(1, "%", 1));
}
