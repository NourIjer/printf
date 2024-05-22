/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nijer <nijer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:38:53 by nijer             #+#    #+#             */
/*   Updated: 2024/03/12 02:52:10 by nijer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>

//printf.c:
void	ft_putchar(char c, int *len);
int		ft_putstr(char *s);
int		ft_putunbr(unsigned int n);
int		handle_format(char format, va_list args);
int		ft_printf(const char *format, ...);

//put_hexa.c:
int		ft_puthexa(size_t n, char format);

//put_nbr.c:
int		ft_putnbr(int n);

#endif
