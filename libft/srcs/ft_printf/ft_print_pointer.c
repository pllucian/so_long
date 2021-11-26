/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:02:17 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:00:50 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(size_t nbr, t_struct *flags)
{
	char	*str;

	str = ft_ulltoa_base(nbr, 16);
	str = ft_str_tolower(str);
	if (flags->minus)
	{
		flags->length += ft_print_type("0x", 2);
		flags->length += ft_print_type(str, ft_strlen(str));
	}
	flags->length += ft_print_width(flags->width, ft_strlen(str) + 2, 0);
	if (!flags->minus)
	{
		flags->length += ft_print_type("0x", 2);
		flags->length += ft_print_type(str, ft_strlen(str));
	}
	free(str);
}
