/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:30:17 by nijer             #+#    #+#             */
/*   Updated: 2024/03/12 17:28:14 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

int	ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		ft_putchar(*s, &len);
		s++;
	}
	return (len);
}

int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putunbr(n / 10);
	ft_putchar(n % 10 + '0', &len);
	return (len);
}

int	handle_format(char format, va_list args)
{
	int	len;
	int	num;

	num = 0;
	len = 0;
	if (format == 'c')
		ft_putchar((char)va_arg(args, int), &len);
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthexa(va_arg(args, size_t), format);
	else if (format == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthexa((size_t)va_arg(args, void *), 'x');
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ft_putchar('%', &len);
			else
				len += handle_format(*format, args);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
