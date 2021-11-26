/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 08:26:29 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:00:00 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, t_struct *flags)
{
	if (flags->minus)
		ft_putchar_fd(c, 1);
	flags->length += ft_print_width(flags->width, 1, 0);
	if (!flags->minus)
		ft_putchar_fd(c, 1);
	flags->length++;
}
