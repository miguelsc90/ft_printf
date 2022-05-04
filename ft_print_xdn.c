/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xdn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misanche <misanche@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:45:26 by misanche          #+#    #+#             */
/*   Updated: 2022/05/04 19:10:17 by misanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_xdn(unsigned int num)
{
	char	num_fin;
	int		len;
	char	*list;

	len = 0;
	list = "0123456789abcdef";
	if (num >= 16)
	{
		len += (ft_put_xdn(num / 16));
	}
	num_fin = list[num % 16];
	len += write(1, &num_fin, 1);
	return (len);
}

int	ft_print_xdn(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		len = ft_put_xdn(num);
		return (len);
	}
}
