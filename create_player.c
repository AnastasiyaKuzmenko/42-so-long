/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:57:42 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/17 17:28:35 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (player == NULL)
		return (0);
	player->x_player = 0;
	player->y_player = 0;
	player->x_target = 1;
	player->y_target = 1;
	player->win = 0;
	player->moves = 0;
	return (player);
}

void	init_position(t_map *map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				player->x_player = x;
				player->y_player = y;
			}
			x++;
		}
		y++;
	}
}
