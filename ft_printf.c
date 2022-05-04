/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misanche <misanche@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:29:32 by misanche          #+#    #+#             */
/*   Updated: 2022/05/04 18:36:31 by misanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	check(va_list args, const char format)
{
	int	lenght;

	lenght = 0;
	if (format == 'c')
		lenght = ft_printchar(va_arg(args, int));
	else if (format == 's')
		lenght = ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		lenght = ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		lenght = ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		lenght = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		lenght = ft_print_xdn(va_arg(args, unsigned int));
	else if (format == 'X')
		lenght = ft_print_xup(va_arg(args, unsigned int));
	else if (format == '%')
		lenght = ft_print_percent();
	return (lenght);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = len + check(args, str[i + 1]);
			i++;
		}
		else
		{
			len = len + ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int main()
{
	//char *n;
	int p = 0;
	int pa = 0;

	//n = "hola que tal estas";
	p = ft_printf("%x", 100);
	pa = printf("\n%x", 100);
   	printf("\n %i --> %i", p, pa);	
	return (0);
}*/
