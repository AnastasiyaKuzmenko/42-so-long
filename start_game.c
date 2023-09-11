/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:40:19 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/19 11:48:22 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_game *game)
{
	free_exit(game);
	return (1);
}

static char	init_target(int keycode, t_game *game)
{
	char	c;

	if (keycode == 0)
	{
		game->player->x_target = game->player->x_player - 1;
		game->player->y_target = game->player->y_player;
	}
	else if (keycode == 2)
	{
		game->player->x_target = game->player->x_player + 1;
		game->player->y_target = game->player->y_player;
	}
	else if (keycode == 1)
	{
		game->player->x_target = game->player->x_player;
		game->player->y_target = game->player->y_player + 1;
	}
	else if (keycode == 13)
	{
		game->player->x_target = game->player->x_player;
		game->player->y_target = game->player->y_player - 1;
	}
	c = game->map->map[game->player->y_target][game->player->x_target];
	return (c);
}

static void	player_wins(int keycode, t_game *game)
{
	move(keycode, game);
	game->player->win = 1;
	draw_win(game);
}

static int	check_target(int keycode, t_game *game)
{
	char	c;

	if (keycode == 53)
		free_exit(game);
	else if (game->player->win == 0)
	{
		c = init_target(keycode, game);
		if (c == '0')
			move(keycode, game);
		else if (c == 'P' || c == 'C')
		{
			if (c == 'C')
				game->map->collectible--;
			move(keycode, game);
			game->map->map[game->player->y_target]
			[game->player->x_target] = '0';
		}
		else if (c == 'E' && game->map->collectible == 0)
			player_wins(keycode, game);
		if ((c == '0' || c == 'C') && (keycode == 0
				|| keycode == 1 || keycode == 2 || keycode == 13))
			step_count(game);
	}
	return (1);
}

void	start_game(t_game *game)
{
	mlx_key_hook(game->mlx_win, check_target, game);
	mlx_hook(game->mlx_win, 17, 0L, close_window, game);
}
