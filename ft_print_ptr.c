/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misanche <misanche@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:45:26 by misanche          #+#    #+#             */
/*   Updated: 2022/05/04 18:28:46 by misanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	i;

	i = 0;
	while (num)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t num)
{
	char	numfin;

	numfin = '0';
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
		{
			numfin = num + '0';
			write(1, &numfin, 1);
		}
		else
		{
			numfin = num - 10 + 'a';
			write(1, &numfin, 1);
		}
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	ptr_lenght;

	ptr_lenght = 0;
	ptr_lenght += write(1, "0x", 2);
	if (ptr == 0)
	{
		ptr_lenght += write(1, "0", 1);
	}
	else
	{
		ft_put_ptr(ptr);
		ptr_lenght += ft_ptr_len(ptr);
	}
	return (ptr_lenght);
}
