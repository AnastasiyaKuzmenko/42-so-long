/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:12:19 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/17 18:36:15 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_game(t_map *map, t_player *player, t_img *images)
{
	t_game	*game;

	game = NULL;
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return (NULL);
	game->images = images;
	game->player = player;
	game->map = map;
	return (game);
}

void	step_count(t_game *game)
{
	char	*str;
	char	*step_str;
	char	*new_str;

	game->player->moves += 1;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->images->wall, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->images->wall, 64, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->images->wall, 128, 0);
	step_str = "Step Count: ";
	str = ft_itoa(game->player->moves);
	new_str = ft_strjoin(step_str, str);
	mlx_string_put(game->mlx, game->mlx_win, 20, 20, 0xFFFFFF, new_str);
	free(str);
	free(new_str);
}
