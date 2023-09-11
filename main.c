/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:54:20 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/19 17:09:36 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_screen(t_map *map, t_player *player)
{
	void	*mlx;
	void	*mlx_win;
	t_img	*images;
	t_game	*game;

	images = NULL;
	images = (t_img *)malloc(sizeof(t_img));
	if (images == NULL)
		return ;
	game = init_game(map, player, images);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 64 * map->width, 64 * map->height, "so_long");
	fill_images(images, mlx);
	draw_map(mlx, mlx_win, map, images);
	game->mlx_win = mlx_win;
	game->mlx = mlx;
	start_game(game);
	mlx_loop(mlx);
}

static int	check_args_format(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		ft_print_str("Error\n");
		ft_print_str("Not enough arguments/too many arguments!\n");
		return (0);
	}
	len = ft_strlen(argv[1]) - 1;
	if (argv[1][len] != 'r' || argv[1][len - 1] != 'e' ||
		argv[1][len - 2] != 'b' || argv[1][len - 3] != '.')
	{
		ft_print_str("Error\n");
		ft_print_str("Invalid file format!\n");
		return (0);
	}
	return (1);
}

static int	check_file(char **argv)
{
	int		fd;
	char	buffer[2];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_print_str("Error\n");
		ft_print_str("File doesn't exist!\n");
		return (0);
	}
	if (read(fd, buffer, 1) < 1)
	{
		ft_print_str("Error\n");
		ft_print_str("File is empty!\n");
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_player	*player;

	map = NULL;
	player = NULL;
	if (check_args_format(argc, argv) == 1 && check_file(argv) == 1)
	{
		map = read_map(argv);
		player = init_player();
		init_position(map, player);
		check_map(map, player);
		if (map->height > 20 || map->width > 40)
		{
			exit_message("Map will not fit for window!\n", map, player);
		}
		init_screen(map, player);
	}
	free(map);
	free(player);
	return (0);
}
