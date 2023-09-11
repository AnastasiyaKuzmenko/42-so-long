/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:46:33 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/19 15:51:19 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_mandatory_map(t_map *map)
{
	if (map->start != 1 || map->collectible == 0 || map->exit != 1)
	{
		return (0);
	}
	return (1);
}

static int	check_rectangular(t_map *map)
{
	if (map->width == map->height)
	{
		return (0);
	}
	return (1);
}

static int	check_borders(t_map *map, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[y][i] && i < map->width)
	{
		if (map->map[y][i] != '1')
		{
			return (0);
		}
		i++;
	}
	while (map->map[j] && j < map->height)
	{
		if (map->map[j][x] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

void	check_path(t_map *map, int x, int y)
{
	if (map->reached_exit == 1 && map->check_collectible == map->collectible)
		map->valid_path = 1;
	if (map->map_tmp[y][x] == 'E')
		map->reached_exit = 1;
	if (map->map_tmp[y][x] == 'P' || map->map_tmp[y][x] == '0'
		|| map->map_tmp[y][x] == 'C')
	{
		if (map->map_tmp[y][x] == 'C')
			map->check_collectible++;
		map->map_tmp[y][x] = 'X';
		if (x < map->width - 1)
			check_path(map, x + 1, y);
		if (y < map->height - 1)
			check_path(map, x, y + 1);
		if (x > 0)
			check_path(map, x - 1, y);
		if (y > 0)
			check_path(map, x, y - 1);
	}
}

void	check_map(t_map *map, t_player *player)
{
	check_path(map, player->x_player, player->y_player);
	if (check_mandatory_map(map) == 0)
		exit_message("Duplicates or missing objects!\n", map, player);
	else if (check_rectangular(map) == 0)
		exit_message("Map is not a rectangular!\n", map, player);
	else if (map->valid_path == 0)
		exit_message("Map has a invalid path!\n", map, player);
	else if (check_borders(map, 0, 0) == 0
		|| check_borders(map, map->height - 1, map->width - 1) == 0)
	{
		exit_message("Map is not surrounded by walls!\n", map, player);
	}
}
