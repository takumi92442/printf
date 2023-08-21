/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:18:48 by marvin            #+#    #+#             */
/*   Updated: 2023/08/22 00:38:05 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h>
# include <unistd.h>


int     ft_printf(const char *, ...);
int baseC(char C);
int ft_strlen(const char *S);
int  baseS(const char *S);

#endif