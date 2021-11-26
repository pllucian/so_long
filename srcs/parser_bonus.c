/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pllucian <pllucian@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:27:08 by pllucian          #+#    #+#             */
/*   Updated: 2021/11/26 18:09:36 by pllucian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map_part2(t_data *data, int i, int j)
{
	if (!ft_strchr("01CEPX", data->map.map[i][j]) \
		|| ((i == 0 || i == data->map.height - 1) \
		&& data->map.map[i][j] != '1'))
		return (EXIT_FAILURE);
	if (data->map.map[i][j] == 'C')
		data->map.count_c++;
	else if (data->map.map[i][j] == 'E')
		data->map.count_e++;
	else if (data->map.map[i][j] == 'P')
	{
		data->plr.pos_x = j;
		data->plr.pos_y = i;
		data->map.count_p++;
	}
	else if (data->map.map[i][j] == 'X')
		data->map.count_x++;
	return (EXIT_SUCCESS);
}

int	check_map_part(t_data *data, int i)
{
	int			j;

	j = -1;
	while (++j < data->map.width)
	{
		if (check_map_part2(data, i, j))
			return (EXIT_FAILURE);
	}
	if (data->map.map[i][0] != '1' || data->map.map[i][j - 1] != '1'\
		|| data->map.count_e > 1 || data->map.count_p > 1 \
		|| (i == data->map.height - 1 \
		&& (!data->map.count_c || !data->map.count_e \
		|| !data->map.count_p || !data->map.count_x)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	check_map(t_data *data)
{
	int		i;

	data->map.width = (int)ft_strlen(data->map.map[0]);
	i = -1;
	while (++i < data->map.height)
	{
		if (data->map.width != (int)ft_strlen(data->map.map[i]))
			exit_error(data, EPERM, "The map must be rectangular");
		if (check_map_part(data, i))
			exit_error(data, EPERM, "Invalid map");
	}
}

void	parse_map(t_data *data, t_list *map)
{
	int		i;

	data->map.height = ft_lstsize(map);
	data->map.map = (char **)ft_calloc(data->map.height + 1, sizeof(char *));
	i = -1;
	while (map)
	{
		data->map.map[++i] = (char *)map->content;
		map = map->next;
	}
}

void	parse_file(t_data *data, char *path)
{
	int		fd;
	char	*line;
	t_list	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error(data, errno, path);
	map = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&map, ft_lstnew(line));
	ft_lstadd_back(&map, ft_lstnew(line));
	parse_map(data, map);
	ft_lstclear(&map, NULL);
	check_map(data);
}
