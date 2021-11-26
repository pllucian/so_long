/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:36:03 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/26 17:16:03 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_data *data)
{
	if (data->plr.pos_x < data->map.width - 1 \
		&& data->map.map[data->plr.pos_y][data->plr.pos_x + 1] != '1')
	{
		if (data->map.map[data->plr.pos_y][data->plr.pos_x + 1] == 'C')
			data->map.count_c--;
		else if (data->map.map[data->plr.pos_y][data->plr.pos_x + 1] == 'E' \
			&& data->map.count_c)
			return ;
		else if (data->map.map[data->plr.pos_y][data->plr.pos_x + 1] == 'E' \
			&& !data->map.count_c)
		{
			ft_printf("steps = %d\nWIN!!!\n", ++data->plr.steps);
			exit_free(data);
		}
		data->map.map[data->plr.pos_y][data->plr.pos_x] = '0';
		data->plr.pos_x++;
		data->map.map[data->plr.pos_y][data->plr.pos_x] = 'P';
		ft_printf("steps = %d\n", ++data->plr.steps);
	}
}

void	move_left(t_data *data)
{
	if (data->plr.pos_x > 0 \
		&& data->map.map[data->plr.pos_y][data->plr.pos_x - 1] != '1')
	{
		if (data->map.map[data->plr.pos_y][data->plr.pos_x - 1] == 'C')
			data->map.count_c--;
		else if (data->map.map[data->plr.pos_y][data->plr.pos_x - 1] == 'E' \
			&& data->map.count_c)
			return ;
		else if (data->map.map[data->plr.pos_y][data->plr.pos_x - 1] == 'E' \
			&& !data->map.count_c)
		{
			ft_printf("steps = %d\nWIN!!!\n", ++data->plr.steps);
			exit_free(data);
		}
		data->map.map[data->plr.pos_y][data->plr.pos_x] = '0';
		data->plr.pos_x--;
		data->map.map[data->plr.pos_y][data->plr.pos_x] = 'P';
		ft_printf("steps = %d\n", ++data->plr.steps);
	}
}

void	move_down(t_data *data)
{
	if (data->plr.pos_y < data->map.height - 1 \
		&& data->map.map[data->plr.pos_y + 1][data->plr.pos_x] != '1')
	{
		if (data->map.map[data->plr.pos_y + 1][data->plr.pos_x] == 'C')
			data->map.count_c--;
		else if (data->map.map[data->plr.pos_y + 1][data->plr.pos_x] == 'E' \
			&& data->map.count_c)
			return ;
		else if (data->map.map[data->plr.pos_y + 1][data->plr.pos_x] == 'E' \
			&& !data->map.count_c)
		{
			ft_printf("steps = %d\nWIN!!!\n", ++data->plr.steps);
			exit_free(data);
		}
		data->map.map[data->plr.pos_y][data->plr.pos_x] = '0';
		data->plr.pos_y++;
		data->map.map[data->plr.pos_y][data->plr.pos_x] = 'P';
		ft_printf("steps = %d\n", ++data->plr.steps);
	}
}

void	move_up(t_data *data)
{
	if (data->plr.pos_y > 0 \
		&& data->map.map[data->plr.pos_y - 1][data->plr.pos_x] != '1')
	{
		if (data->map.map[data->plr.pos_y - 1][data->plr.pos_x] == 'C')
			data->map.count_c--;
		else if (data->map.map[data->plr.pos_y - 1][data->plr.pos_x] == 'E' \
			&& data->map.count_c)
			return ;
		else if (data->map.map[data->plr.pos_y - 1][data->plr.pos_x] == 'E' \
			&& !data->map.count_c)
		{
			ft_printf("steps = %d\nWIN!!!\n", ++data->plr.steps);
			exit_free(data);
		}
		data->map.map[data->plr.pos_y][data->plr.pos_x] = '0';
		data->plr.pos_y--;
		data->map.map[data->plr.pos_y][data->plr.pos_x] = 'P';
		ft_printf("steps = %d\n", ++data->plr.steps);
	}
}
