/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:55:41 by nijer             #+#    #+#             */
/*   Updated: 2024/03/12 16:41:02 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(size_t n, char format)
{
	char		*hex_chars;
	int			len;

	len = 0;
	if (format == 'X')
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";
	if (n >= 16)
		len += ft_puthexa(n / 16, format);
	ft_putchar(hex_chars[n % 16], &len);
	return (len);
}
