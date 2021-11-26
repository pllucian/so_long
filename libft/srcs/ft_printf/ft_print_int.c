/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:33:31 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:00:39 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_int_part(char *str, int sign, t_struct *flags)
{
	if (flags->minus)
	{
		if (sign)
			ft_putchar_fd('-', 1);
		if (flags->precision >= 0)
			flags->length += \
			ft_print_width(flags->precision, ft_strlen(str), 1);
		flags->length += ft_print_type(str, ft_strlen(str));
	}
	if (sign && flags->zero)
		ft_putchar_fd('-', 1);
	if (flags->precision >= 0)
		flags->length += ft_print_width(flags->width, flags->precision, 0);
	else
		flags->length += \
		ft_print_width(flags->width, ft_strlen(str), flags->zero);
	if (!flags->minus)
	{
		if (sign && !flags->zero)
			ft_putchar_fd('-', 1);
		if (flags->precision >= 0)
			flags->length += \
			ft_print_width(flags->precision, ft_strlen(str), 1);
		flags->length += ft_print_type(str, ft_strlen(str));
	}
}

void	ft_print_int(int nbr, t_struct *flags)
{
	char	*str;
	char	sign;

	sign = 0;
	if (!nbr && !flags->precision)
	{
		flags->length += ft_print_width(flags->width, 0, 0);
		return ;
	}
	if (nbr < 0 && nbr > -2147483648)
	{
		nbr *= -1;
		sign = 1;
		flags->width--;
		flags->length++;
	}
	str = ft_itoa(nbr);
	if (flags->precision >= 0)
		flags->zero = 0;
	if (flags->precision >= 0 && (size_t)flags->precision < ft_strlen(str))
		flags->precision = ft_strlen(str);
	ft_print_int_part(str, sign, flags);
	free(str);
}
