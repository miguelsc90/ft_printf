/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misanche <misanche@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:40:43 by misanche          #+#    #+#             */
/*   Updated: 2022/05/04 18:50:11 by misanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

int	ft_printf(const char *str, ...);
int	ft_printstr(char *s);
int	ft_print_ptr(unsigned long long ptr);
int	ft_printnbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_xdn(unsigned int num);
int	ft_print_percent(void);
int	ft_print_xup(unsigned int num);

#endif
