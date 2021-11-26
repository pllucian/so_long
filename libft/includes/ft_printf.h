/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:36:53 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/20 22:41:55 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define TYPES "cspdiuxX%"
# define FLAGS "-0.*"

typedef struct s_struct
{
	char	minus;
	char	zero;
	int		width;
	int		precision;
	char	type;
	int		length;
}		t_struct;

int		ft_printf(const char *format, ...);
void	ft_parse_format(const char *format, va_list ap, t_struct *flags);
void	ft_init_flags(t_struct *flags);
char	*ft_parse_flags(const char *format, va_list ap, t_struct *flags);
void	ft_print_format(char type, va_list ap, t_struct *flags);

void	ft_print_char(char c, t_struct *flags);
void	ft_print_string(char *str, t_struct *flags);
void	ft_print_pointer(size_t nbr, t_struct *flags);
void	ft_print_int(int nbr, t_struct *flags);
void	ft_print_uint(unsigned int nbr, t_struct *flags);
void	ft_print_hex(unsigned int nbr, t_struct *flags);
void	ft_print_percent(t_struct *flags);

int		ft_print_width(int width, int diff, int zero);
int		ft_print_type(char *str, int precision);

void	ft_flag_minus(t_struct *flags);
void	ft_flag_zero(t_struct *flags);
void	ft_flag_digit(char c, t_struct *flags);
char	*ft_flag_precision(const char *format, va_list ap, t_struct *flags);
void	ft_flag_star(va_list ap, t_struct *flags);

char	*ft_ulltoa_base(unsigned long long nbr, int base);
char	*ft_str_tolower(char *str);

#endif
