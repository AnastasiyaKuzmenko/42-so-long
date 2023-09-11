/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:04:12 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/19 11:21:25 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_message(char *str, t_map *map, t_player *player)
{
	if (ft_strlen(str) > 1)
	{
		ft_print_str("Error\n");
		ft_print_str(str);
		free_map(map->map);
		free_map(map->map_tmp);
		free(player);
		free(map);
		exit(1);
	}
}

void	exit_message_beginning(char *str)
{
	if (ft_strlen(str) > 1)
	{
		ft_print_str("Error\n");
		ft_print_str(str);
		exit(1);
	}
}

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->images->collect);
	mlx_destroy_image(game->mlx, game->images->exit);
	mlx_destroy_image(game->mlx, game->images->wall);
	mlx_destroy_image(game->mlx, game->images->floor);
	mlx_destroy_image(game->mlx, game->images->character);
}

void	free_map(char **map)
{
	int	index;

	index = 0;
	while (map[index])
	{
		free(map[index]);
		index++;
	}
	free(map);
}

void	free_exit(t_game *game)
{
	free_images(game);
	free(game->images);
	free(game->player);
	free_map(game->map->map);
	free_map(game->map->map_tmp);
	free(game->map);
	mlx_clear_window(game->mlx, game->mlx_win);
	free(game);
	exit(1);
}
