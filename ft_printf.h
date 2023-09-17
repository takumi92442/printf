/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taksato <taksato@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:18:48 by marvin            #+#    #+#             */
/*   Updated: 2023/09/17 13:20:44 by taksato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <inttypes.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	base_c(char C);
int	ft_strlen(const char *S);
int	base_s(const char *S);
int	base_ten(int number);
int	base_pointer(uintptr_t p);
int	big_base_sixteen(unsigned int number);
int	smallbase_sixteen(unsigned int number);
int	unsigned_base_ten(unsigned int number);
int	persent(void);
#endif