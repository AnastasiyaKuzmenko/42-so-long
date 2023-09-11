/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:28:23 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/19 11:48:54 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moving_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->floor,
		game->player->x_player * 64, game->player->y_player * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->floor,
		game->player->x_target * 64, game->player->y_target * 64);
	game->player->x_player--;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->character,
		game->player->x_player * 64, game->player->y_player * 64);
}

static void	moving_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->floor,
		game->player->x_player * 64, game->player->y_player * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->floor,
		game->player->x_target * 64, game->player->y_target * 64);
	game->player->x_player++;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->character,
		game->player->x_player * 64, game->player->y_player * 64);
}

static void	moving_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->floor,
		game->player->x_player * 64, game->player->y_player * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->floor,
		game->player->x_target * 64, game->player->y_target * 64);
	game->player->y_player++;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->character,
		game->player->x_player * 64, game->player->y_player * 64);
}

static void	moving_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->floor,
		game->player->x_player * 64, game->player->y_player * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->floor,
		game->player->x_target * 64, game->player->y_target * 64);
	game->player->y_player--;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->character,
		game->player->x_player * 64, game->player->y_player * 64);
}

void	move(int keycode, t_game *game)
{
	if (keycode == 0)
	{
		moving_left(game);
	}
	else if (keycode == 2)
	{
		moving_right(game);
	}
	else if (keycode == 1)
	{
		moving_down(game);
	}
	else if (keycode == 13)
	{
		moving_up(game);
	}
}
