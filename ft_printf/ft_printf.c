/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibsenad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 01:18:17 by hibsenad          #+#    #+#             */
/*   Updated: 2025/06/22 02:50:48 by hibsenad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char mod, va_list args)
{
	int		count;
	void	*ptr;

	count = 0;
	if (mod == 'c')
		count += ft_putchar(va_arg(args, int));
	if (mod == '%')
		count = ft_putchar('%');
	if (mod == 'i' || mod == 'd')
		count += ft_putnbr(va_arg(args, int));
	if (mod == 'u')
		count += ft_put_u_nbr(va_arg(args, unsigned int));
	if (mod == 's')
		count += ft_putstr(va_arg(args, char *));
	if (mod == 'p')
	{
		ptr = va_arg(args, void *);
		count += ft_putphexa((unsigned long long)ptr, 'p');
	}
	if (mod == 'x')
		count += ft_putphexa(va_arg(args, unsigned int), 'x');
	if (mod == 'X')
		count += ft_putphexa(va_arg(args, unsigned int), 'X');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		result;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			result += ft_conversion(format[i], args);
		}
		else
			result += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (result);
}
