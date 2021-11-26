/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:28:28 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:40:02 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_uint_part(char *str, t_struct *flags)
{
	if (flags->minus)
	{
		if (flags->precision >= 0)
			flags->length += \
			ft_print_width(flags->precision, ft_strlen(str), 1);
		flags->length += ft_print_type(str, ft_strlen(str));
	}
	if (flags->precision >= 0)
		flags->length += ft_print_width(flags->width, flags->precision, 0);
	else
		flags->length += \
		ft_print_width(flags->width, ft_strlen(str), flags->zero);
	if (!flags->minus)
	{
		if (flags->precision >= 0)
			flags->length += \
			ft_print_width(flags->precision, ft_strlen(str), 1);
		flags->length += ft_print_type(str, ft_strlen(str));
	}
}

void	ft_print_uint(unsigned int nbr, t_struct *flags)
{
	char	*str;

	if (!nbr && !flags->precision)
	{
		flags->length += ft_print_width(flags->width, 0, 0);
		return ;
	}
	str = ft_ulltoa_base(nbr, 10);
	if (flags->precision >= 0)
		flags->zero = 0;
	if (flags->precision >= 0 && (size_t)flags->precision < ft_strlen(str))
		flags->precision = ft_strlen(str);
	ft_print_uint_part(str, flags);
	free(str);
}
