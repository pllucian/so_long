/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:37:30 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/26 17:19:20 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bits_pp / 8));
	return (*(int *)dest);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bits_pp / 8));
	*(int *)dest = color;
}

void	draw_texture(t_data *data, t_img *img, int i, int j)
{
	int		color;
	int		y;
	int		x;

	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			color = my_mlx_pixel_get(img, x, y);
			if (color != 0x00cd00cd)
				my_mlx_pixel_put(&data->map_img, \
					(64 * j) + x, (64 * i) + y, color);
		}
	}
}

int	render(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map.height)
	{
		j = -1;
		while (++j < data->map.width)
		{
			draw_texture(data, &data->empty_img, i, j);
			if (data->map.map[i][j] == '1')
				draw_texture(data, &data->wall_img, i, j);
			else if (data->map.map[i][j] == 'C')
				draw_texture(data, &data->collect_img, i, j);
			else if (data->map.map[i][j] == 'E')
				draw_texture(data, &data->exit_img, i, j);
			else if (data->map.map[i][j] == 'P')
				draw_texture(data, &data->plr_img, i, j);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->map_img.img, 0, 0);
	return (EXIT_SUCCESS);
}
