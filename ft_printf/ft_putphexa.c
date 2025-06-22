/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putphexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibsenad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:31:40 by hibsenad          #+#    #+#             */
/*   Updated: 2025/06/22 02:53:54 by hibsenad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putphexa(unsigned long nb, int xorp)
{
	char	*base;
	int		count;

	count = 0;
	if (xorp == 'x' || xorp == 'p')
		base = "0123456789abcdef";
	else if (xorp == 'X')
		base = "0123456789ABCDEF";
	if (xorp == 'p')
	{
		if (!nb)
		{
			count += ft_putstr("(nil)");
			return (count);
		}
		count += ft_putchar('0');
		count += ft_putchar('x');
		xorp = 'x';
	}
	if (nb >= 16)
	{
		count += ft_putphexa((nb / 16), xorp);
	}
	count += ft_putchar(base[nb % 16]);
	return (count);
}
