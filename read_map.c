/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmenk <akuzmenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:15:30 by akuzmenk          #+#    #+#             */
/*   Updated: 2023/06/19 15:11:23 by akuzmenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(void)
{	
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = 0;
	map->height = 0;
	map->start = 0;
	map->collectible = 0;
	map->check_collectible = 0;
	map->exit = 0;
	map->reached_exit = 0;
	map->valid_path = 0;
	map->map = NULL;
	map->map_tmp = NULL;
	return (map);
}

void	get_height_width(char **argv, t_map *map)
{
	int		fd;
	int		len;
	int		tmp;
	char	*line;

	len = 0;
	tmp = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		if (tmp == 0)
			tmp = len;
		map->height++;
		free(line);
		if (tmp != len)
			exit_message_beginning("Not all lines have the same length!\n");
	}
	map->width = len;
	close(fd);
}

void	fill_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*holder_map;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return ;
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = holder_map;
		holder_map = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	map->map = ft_split(holder_map, '\n');
	map->map_tmp = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
}

int	is_char_allowed(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != '\n')
	{
		return (0);
	}
	return (1);
}

t_map	*read_map(char **argv)
{
	t_map	*map;
	int		fd;
	char	buffer[2];

	map = NULL;
	map = init_map();
	get_height_width(argv, map);
	fill_map(argv, map);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, buffer, 1))
	{
		if (is_char_allowed(buffer[0]) == 0)
			exit_message_beginning("Invalid character in map\n");
		if (buffer[0] == 'P')
			map->start += 1;
		else if (buffer[0] == 'C')
			map->collectible += 1;
		else if (buffer[0] == 'E')
			map->exit += 1;
	}
	close(fd);
	return (map);
}
