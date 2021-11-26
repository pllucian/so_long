/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:57:09 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/26 21:40:40 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_data_mlx(t_data *data)
{
	if (data->enemy_img_rbonus.img)
		mlx_destroy_image(data->mlx, data->enemy_img_rbonus.img);
	if (data->enemy_img_lbonus.img)
		mlx_destroy_image(data->mlx, data->enemy_img_lbonus.img);
	if (data->plr_img_rbonus.img)
		mlx_destroy_image(data->mlx, data->plr_img_rbonus.img);
	if (data->plr_img_lbonus.img)
		mlx_destroy_image(data->mlx, data->plr_img_lbonus.img);
	if (data->exit_img.img)
		mlx_destroy_image(data->mlx, data->exit_img.img);
	if (data->collect_img.img)
		mlx_destroy_image(data->mlx, data->collect_img.img);
	if (data->wall_img.img)
		mlx_destroy_image(data->mlx, data->wall_img.img);
	if (data->empty_img.img)
		mlx_destroy_image(data->mlx, data->empty_img.img);
	if (data->map_img.img)
		mlx_destroy_image(data->mlx, data->map_img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	free_data(t_data *data)
{
	if (data->mlx)
		free_data_mlx(data);
	free(data->map.enemy_path_rbonus);
	free(data->map.enemy_path_lbonus);
	free(data->map.plr_path_rbonus);
	free(data->map.plr_path_lbonus);
	free(data->map.exit_path);
	free(data->map.collect_path);
	free(data->map.wall_path);
	free(data->map.empty_path);
	if (data->map.map)
		ft_freearray((void **)data->map.map);
	free(data);
}

void	exit_error(t_data *data, int error, char *message)
{
	ft_putendl_fd("Error", 2);
	errno = error;
	perror(message);
	if (data)
		free_data(data);
	exit(errno);
}

void	check_args(t_data *data, int argc, char **argv)
{
	if (argc < 2)
		exit_error(data, EINVAL, \
		"The first argument must be a map description file");
	else if (!ft_strrchr(argv[1], '.') \
		|| ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5))
		exit_error(data, EINVAL, \
		"The filename doesn't end with the `.ber` extension");
	else if (argc > 2)
		exit_error(data, E2BIG, "Too many arguments");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	data->map.empty_path = ft_strdup("./pics/empty.xpm");
	data->map.wall_path = ft_strdup("./pics/wall.xpm");
	data->map.collect_path = ft_strdup("./pics/collectible.xpm");
	data->map.exit_path = ft_strdup("./pics/exit.xpm");
	data->map.plr_path_lbonus = ft_strdup("./pics/player.xpm");
	data->map.plr_path_rbonus = ft_strdup("./pics/player_bonus.xpm");
	data->map.enemy_path_lbonus = ft_strdup("./pics/enemy.xpm");
	data->map.enemy_path_rbonus = ft_strdup("./pics/enemy_bonus.xpm");
	check_args(data, argc, argv);
	parse_file(data, argv[1]);
	game(data);
	if (data)
		free_data(data);
	return (EXIT_SUCCESS);
}
