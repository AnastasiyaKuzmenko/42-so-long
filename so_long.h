/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:31:26 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/19 15:00:46 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_map
{
	int		height;
	int		width;
	int		collectible;
	int		check_collectible;
	int		exit;
	int		reached_exit;
	int		start;
	int		valid_path;
	char	**map;
	char	**map_tmp;

}	t_map;

typedef struct s_player
{
	int	x_player;
	int	y_player;
	int	x_target;
	int	y_target;
	int	win;
	int	moves;

}	t_player;

typedef struct s_img
{
	void	*collect;
	void	*exit;
	void	*wall;
	void	*floor;
	void	*character;
	void	*win;
	char	*collect_path;
	char	*exit_path;
	char	*wall_path;
	char	*floor_path;
	char	*character_path;
	char	*win_path;

	int		x_image;
	int		y_image;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_img		*images;
	t_player	*player;
	t_map		*map;
}	t_game;

void		init_screen(t_map *map, t_player *player);

void		check_map(t_map *map, t_player *player);

t_map		*read_map(char **argv);
t_map		*init_map(void);
void		fill_map(char **argv, t_map *map);
void		get_height_width(char **argv, t_map *map);

t_player	*init_player(void);
void		init_position(t_map *map, t_player *player);

void		move(int keycode, t_game *game);

void		draw_map(void *mlx, void *mlx_win, t_map *map, t_img *images);
void		fill_images(t_img *images, void *mlx);
void		draw_images(void *mlx, void *mlx_win, t_img *images, char c);
void		draw_win(t_game *game);

void		start_game(t_game *game);

void		free_exit(t_game *game);
void		free_images(t_game *game);
void		free_map(char **map);
void		exit_message(char *str, t_map *map, t_player *player);
void		exit_message_beginning(char *str);

t_game		*init_game(t_map *map, t_player *player, t_img *images);
void		step_count(t_game *game);

#endif
