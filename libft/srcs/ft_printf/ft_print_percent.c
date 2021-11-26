/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:26:18 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:00:44 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent(t_struct *flags)
{
	if (flags->minus)
		flags->length += ft_print_type("%", 1);
	flags->length += ft_print_width(flags->width, 1, flags->zero);
	if (!flags->minus)
		flags->length += ft_print_type("%", 1);
}
