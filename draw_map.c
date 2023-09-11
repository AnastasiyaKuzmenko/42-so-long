/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:44:22 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/19 16:21:29 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_images(t_img *images, void *mlx)
{
	int	width;
	int	height;

	images->collect_path = "./textures/collect.xpm";
	images->exit_path = "./textures/exit_close.xpm";
	images->wall_path = "./textures/wall.xpm";
	images->floor_path = "./textures/space.xpm";
	images->character_path = "./textures/player_front.xpm";
	images->win_path = "./textures/win_images.xpm";
	images->collect = mlx_xpm_file_to_image(mlx, images->collect_path,
			&width, &height);
	images->exit = mlx_xpm_file_to_image(mlx, images->exit_path,
			&width, &height);
	images->wall = mlx_xpm_file_to_image(mlx, images->wall_path,
			&width, &height);
	images->floor = mlx_xpm_file_to_image(mlx, images->floor_path,
			&width, &height);
	images->character = mlx_xpm_file_to_image(mlx, images->character_path,
			&width, &height);
	images->win = mlx_xpm_file_to_image(mlx, images->win_path,
			&width, &height);
}

void	draw_images(void *mlx, void *mlx_win, t_img *images, char c)
{
	if (c == '0')
	{
		mlx_put_image_to_window(mlx, mlx_win, images->floor,
			images->x_image, images->y_image);
	}
	else if (c == '1')
	{
		mlx_put_image_to_window(mlx, mlx_win, images->wall,
			images->x_image, images->y_image);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(mlx, mlx_win, images->collect,
			images->x_image, images->y_image);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(mlx, mlx_win, images->exit,
			images->x_image, images->y_image);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(mlx, mlx_win, images->character,
			images->x_image, images->y_image);
	}
}

void	draw_map(void *mlx, void *mlx_win, t_map *map, t_img *images)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	j = 0;
	while (map->map[y])
	{
		x = 0;
		i = 0;
		while (map->map[y][x])
		{
			images->x_image = i;
			images->y_image = j;
			draw_images(mlx, mlx_win, images, map->map[y][x]);
			x++;
			i += 64;
		}
		y++;
		j += 64;
	}
}

void	draw_win(t_game *game)
{
	int	width;
	int	height;
	int	x;
	int	y;

	y = 0;
	x = 0;
	width = game->map->width * 100;
	height = game->map->height * 100;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->images->win, x, y);
			y = y + 150;
		}
		x = x + 220;
	}
}
