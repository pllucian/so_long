/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:36:18 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:34:50 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	flags;

	flags.length = 0;
	va_start(ap, format);
	ft_parse_format(format, ap, &flags);
	va_end(ap);
	return (flags.length);
}

void	ft_parse_format(const char *format, va_list ap, t_struct *flags)
{
	while (*format)
	{
		ft_init_flags(flags);
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			flags->length++;
		}
		else
		{
			format = ft_parse_flags(++format, ap, flags);
			if (ft_strchr(TYPES, *format))
				ft_print_format(*format, ap, flags);
		}
		format++;
	}
}

void	ft_init_flags(t_struct *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = -1;
	flags->type = 0;
}

char	*ft_parse_flags(const char *format, va_list ap, t_struct *flags)
{
	while (*format)
	{
		if (*format == '-')
			ft_flag_minus(flags);
		if (*format == '0' && flags->width == 0 && flags->minus == 0)
			ft_flag_zero(flags);
		if (ft_isdigit(*format))
			ft_flag_digit(*format, flags);
		if (*format == '.')
			format = ft_flag_precision(++format, ap, flags);
		if (*format == '*')
			ft_flag_star(ap, flags);
		if (ft_strchr(TYPES, *format))
		{
			flags->type = *format;
			break ;
		}
		format++;
	}
	return ((char *)format);
}

void	ft_print_format(char type, va_list ap, t_struct *flags)
{
	if (type == 'c')
		ft_print_char(va_arg(ap, int), flags);
	if (type == 's')
		ft_print_string(va_arg(ap, char *), flags);
	if (type == 'p')
		ft_print_pointer(va_arg(ap, size_t), flags);
	if (type == 'd' || type == 'i')
		ft_print_int(va_arg(ap, int), flags);
	if (type == 'u')
		ft_print_uint(va_arg(ap, unsigned int), flags);
	if (type == 'x' || type == 'X')
		ft_print_hex(va_arg(ap, unsigned int), flags);
	if (type == '%')
		ft_print_percent(flags);
}
