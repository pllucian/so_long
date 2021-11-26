/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:37:25 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:00:57 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(char *str, t_struct *flags)
{
	if (!str)
		str = "(null)";
	if (flags->precision >= 0 && (size_t)flags->precision > ft_strlen(str))
		flags->precision = ft_strlen(str);
	if (flags->minus)
	{
		if (flags->precision >= 0)
			flags->length += ft_print_type(str, flags->precision);
		else
			flags->length += ft_print_type(str, ft_strlen(str));
	}
	if (flags->precision >= 0)
		flags->length += ft_print_width(flags->width, flags->precision, 0);
	else
		flags->length += ft_print_width(flags->width, ft_strlen(str), 0);
	if (!flags->minus)
	{
		if (flags->precision >= 0)
			flags->length += ft_print_type(str, flags->precision);
		else
			flags->length += ft_print_type(str, ft_strlen(str));
	}
}
