/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:33:27 by akalican          #+#    #+#             */
/*   Updated: 2024/06/04 19:59:23 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include "libft/libft.h"

void	check_horizontal_wall(t_game *data, int index)
{
	int	i;

	i = 0;
	while (i < data->map_width)
	{
		if (data->map.map[index][i] != '1')
		{
			write(1, "Error Invalid map wall", 24);
			exit(1);
		}
		i++;
	}
}

void	check_vertical_wall(t_game *data, int index)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		if (data->map.map[i][index] != '1')
		{
			write(1, "Error Invalid map wall", 24);
			exit(1);
		}
		i++;
	}
}

int	check_map_walls(t_game *data)
{
	check_horizontal_wall(data, 0);
	check_horizontal_wall(data, data->map_height - 1);
	check_vertical_wall(data, 0);
	check_vertical_wall(data, data->map_width - 1);
	return (1);
}

void	check_map_extension(char *filename)
{
	char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || extension == filename
		|| ft_strncmp(extension, ".ber", 4) != 0 || extension == 0)
	{
		write(1, "Error Map file must have .ber extension", 39);
		exit(1);
	}
}

void	check_map_characters(t_game *data, int youare, int stupid)
{
	int	j;
	int	i;

	i = 1;
	j = 0;
	while (youare > i)
	{
		j = 0;
		while (stupid > j)
		{
			if (data->map.map[i][j] != '1'
				&& data->map.map[i][j] != 'P' && data->map.map[i][j] != '0'
				&& data->map.map[i][j] != 'E' && data->map.map[i][j] != 'C')
			{
				write(1, "Error Invalid character in map2", 32);
				exit(1);
			}
					j++;
		}
					i++;
	}
}
