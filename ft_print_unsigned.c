/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misanche <misanche@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 10:45:26 by misanche          #+#    #+#             */
/*   Updated: 2022/05/04 18:29:26 by misanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_len(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		lenght;
	char	*num;

	lenght = 0;
	if (n == 0)
	{
		lenght += write(1, "0", 1);
	}
	else
	{
		num = ft_uitoa(n);
		lenght = ft_printstr(num);
		free(num);
	}
	return (lenght);
}
