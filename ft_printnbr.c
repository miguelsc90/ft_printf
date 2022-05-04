/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misanche <misanche@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:45:26 by misanche          #+#    #+#             */
/*   Updated: 2022/05/04 18:46:39 by misanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int		len;
	char	num;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			len += write(1, "-2", 2);
			n = 147483648;
		}
		else
		{
			len += write(1, "-", 1);
			n *= -1;
		}
	}
	if (n >= 10)
		len += ft_printnbr(n / 10);
	num = (n % 10) + '0';
	len += write(1, &num, 1);
	return (len);
}
