/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:37:41 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/26 21:33:14 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

typedef struct s_plr
{
	int		pos_x;
	int		pos_y;
	int		steps;
}		t_plr;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_pp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		count_c;
	int		count_e;
	int		count_p;
	int		count_x;
	char	*empty_path;
	char	*wall_path;
	char	*collect_path;
	char	*exit_path;
	char	*plr_path_lbonus;
	char	*plr_path_rbonus;
	char	*enemy_path_lbonus;
	char	*enemy_path_rbonus;
	int		res_x;
	int		res_y;
}		t_map;

typedef struct s_data
{
	t_map	map;
	t_plr	plr;
	void	*mlx;
	void	*win;
	t_img	map_img;
	t_img	empty_img;
	t_img	wall_img;
	t_img	collect_img;
	t_img	exit_img;
	t_img	*plr_img_ptr;
	t_img	plr_img_lbonus;
	t_img	plr_img_rbonus;
	t_img	*enemy_img_ptr;
	t_img	enemy_img_lbonus;
	t_img	enemy_img_rbonus;
	int		counter;
}		t_data;

void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_up(t_data *data);

void	print_steps(t_data *data);
int		my_mlx_pixel_get(t_img *img, int x, int y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_texture(t_data *data, t_img *img, int i, int j);
int		render(t_data *data);

int		exit_free(t_data *data);
int		key_press(int key, t_data *data);
void	init_texture(t_data *data, t_img *tex_img, char *file);
void	init_textures(t_data *data);
void	game(t_data *data);

int		check_map_part2(t_data *data, int i, int j);
int		check_map_part(t_data *data, int i);
void	check_map(t_data *data);
void	parse_map(t_data *data, t_list *map);
void	parse_file(t_data *data, char *path);

void	free_data_mlx(t_data *data);
void	free_data(t_data *data);
void	exit_error(t_data *data, int error, char *message);
void	check_args(t_data *data, int argc, char **argv);

#endif
