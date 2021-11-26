/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:52:27 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/23 15:53:21 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freearray(void **array)
{
	void	**tmp;

	if (!array)
		return ;
	tmp = array;
	while (*tmp)
	{
		free(*tmp);
		*tmp++ = NULL;
	}
	free(array);
}
