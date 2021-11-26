/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:59:04 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/26 16:44:26 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_free(t_data *data)
{
	if (data)
		free_data(data);
	exit(EXIT_SUCCESS);
}

int	key_press(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit_free(data);
	if (key == KEY_W)
		move_up(data);
	if (key == KEY_A)
		move_left(data);
	if (key == KEY_S)
		move_down(data);
	if (key == KEY_D)
		move_right(data);
	return (EXIT_SUCCESS);
}

void	init_texture(t_data *data, t_img *tex_img, char *file)
{
	tex_img->img = mlx_xpm_file_to_image(data->mlx, file, \
		&tex_img->width, &tex_img->height);
	if (!tex_img->img)
		exit_error(data, errno, file);
	tex_img->addr = mlx_get_data_addr(tex_img->img, &tex_img->bits_pp, \
	&tex_img->line_len, &tex_img->endian);
}

void	init_textures(t_data *data)
{
	init_texture(data, &data->empty_img, data->map.empty_path);
	init_texture(data, &data->wall_img, data->map.wall_path);
	init_texture(data, &data->collect_img, data->map.collect_path);
	init_texture(data, &data->exit_img, data->map.exit_path);
	init_texture(data, &data->plr_img, data->map.plr_path);
}

void	game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_error(data, errno, "mlx error");
	data->map.res_x = data->map.width * 64;
	data->map.res_y = data->map.height * 64;
	data->win = mlx_new_window(data->mlx, data->map.res_x, \
		data->map.res_y, "so_long");
	data->map_img.img = mlx_new_image(data->mlx, \
		data->map.res_x, data->map.res_y);
	if (!data->win || !data->map_img.img)
		exit_error(data, errno, "mlx error");
	data->map_img.addr = mlx_get_data_addr(data->map_img.img, \
	&data->map_img.bits_pp, &data->map_img.line_len, &data->map_img.endian);
	init_textures(data);
	mlx_hook(data->win, 33, 1L << 17, exit_free, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx, render, data);
	mlx_loop(data->mlx);
}
