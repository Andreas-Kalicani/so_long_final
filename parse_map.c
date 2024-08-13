/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:06:50 by akalican          #+#    #+#             */
/*   Updated: 2024/06/04 20:02:16 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	count_lines(char *path)
{
	int		fd;
	int		number_of_lines;
	char	*read;

	fd = open(path, O_RDONLY);
	read = get_next_line(fd);
	number_of_lines = 0;
	if (fd == -1)
		return (-1);
	while (read != NULL)
	{
		free(read);
		number_of_lines++;
		read = get_next_line(fd);
	}
	free(read);
	close(fd);
	return (number_of_lines);
}

void	element_counter(t_game *data, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			data->map.player_count++;
		if (buffer[i] == 'C')
			data->map.coin_count++;
		if (buffer[i] == 'E')
			data->map.exit_count++;
		i++;
	}
}

int	data_map_coin_exit_check(t_game *data)
{
	if (data->map.player_count != 1)
		return (0);
	if (data->map.coin_count < 1)
		return (0);
	if (data->map.exit_count != 1)
		return (0);
	return (1);
}
/*
int	map_checker(t_game *data)
{
	int		p[2];
	char	**map_dup;

	ft_bzero(p, sizeof(int) * 2);
	if (data_map_coin_exit_check(data) == 0)
		exit(1);
	while (data->map.map[p[1]])
	{
		while (data->map.map[p[1]][p[0]])
		{
			if (data->map.map[p[1]][p[0]] == 'C'
				|| data->map.map[p[1]][p[0]] == 'E')
			{
				map_dup = map_duplicate(data);
				if (check_coin_reach(data, map_dup, p[0], p[1]) == 0)
				{
					exit(1);
				}
				ft_double_pointer_free(map_dup);
			}
			p[0]++;
		}
		p[1]++;
		p[0] = 0;
	}
	return (1);
}
*/

char	**parse(t_game *data)
{
	int		i;
	char	*buffer;

	i = 0;
	data->map.map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	buffer = read_and_trim_line(data->fd);
	if (!buffer)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	data->map_width = ft_strlen(buffer);
	while (buffer)
	{
		process_line(data, data->map.map, buffer, i);
		buffer = read_and_trim_line(data->fd);
		i++;
	}
	data->map.map[i] = NULL;
	if (!map_checker(data) || data->map_height == data->map_width)
		exit(1);
	if (!check_map_walls(data))
		exit(1);
	return (data->map.map);
}
