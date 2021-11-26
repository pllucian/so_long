/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 21:59:43 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:35:23 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_minus(t_struct *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

void	ft_flag_zero(t_struct *flags)
{
	flags->zero = 1;
}

void	ft_flag_digit(char c, t_struct *flags)
{
	flags->width = flags->width * 10 + c - '0';
}

char	*ft_flag_precision(const char *format, va_list ap, t_struct *flags)
{
	if (*format == '*')
	{
		flags->precision = va_arg(ap, int);
		format++;
		if (flags->precision < 0)
			flags->precision = -1;
	}
	else
	{
		flags->precision = 0;
		while (ft_isdigit(*format))
			flags->precision = flags->precision * 10 + *format++ - '0';
	}
	return ((char *)format);
}

void	ft_flag_star(va_list ap, t_struct *flags)
{
	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->zero = 0;
		flags->width *= -1;
	}
}
