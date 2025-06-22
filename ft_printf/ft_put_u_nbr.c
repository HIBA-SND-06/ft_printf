/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibsenad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 02:33:06 by hibsenad          #+#    #+#             */
/*   Updated: 2025/06/22 02:53:16 by hibsenad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u_nbr(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	nb = n;
	if (nb >= 10)
	{
		count += ft_put_u_nbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
