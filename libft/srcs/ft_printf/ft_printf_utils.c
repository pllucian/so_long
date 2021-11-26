/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:47:50 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:39:50 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long long nbr, int base)
{
	int		len;

	len = 1;
	nbr /= base;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_ulltoa_base(unsigned long long nbr, int base)
{
	char				*str;
	int					len;

	len = ft_len(nbr, base);
	str = (char *)(malloc(sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (!nbr)
		str[len] = '0';
	while (nbr)
	{
		if (nbr % base < 10)
			str[len--] = nbr % base + '0';
		else
			str[len--] = nbr % base + 'A' - 10;
		nbr /= base;
	}
	return (str);
}

char	*ft_str_tolower(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (ptr);
}
