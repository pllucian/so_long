/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:11:42 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:02:48 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(int width, int diff, int zero)
{
	int		len;

	len = 0;
	while (width - diff > 0)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width -= 1;
		len++;
	}
	return (len);
}

int	ft_print_type(char *str, int precision)
{
	int		len;

	len = 0;
	while (*str && len < precision)
	{
		ft_putchar_fd(*str++, 1);
		len++;
	}
	return (len);
}
