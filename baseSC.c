/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseSC.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:06:42 by takumi            #+#    #+#             */
/*   Updated: 2023/08/23 00:19:42 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int baseC(char C)
{
    return write(1, &C, 1); 
}

int ft_strlen(const char *S)
{
    int count;
    
    count = 0;
    while(*S != '\0')
    {
        count++;
        S++;
    }
    return (count);
}

int  baseS(const char *S)
{
    int count;
    if(S == NULL)
        return (write(1,"(null)",6));
    count = ft_strlen(S);
    return write(1,S, count);
}

int Persent()
{
    return write(1, "%", 1); 
}