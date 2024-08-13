/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:03 by andreasgjer       #+#    #+#             */
/*   Updated: 2024/06/10 14:18:53 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./error.h"
#include "./libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

static void	draw_element(t_game *data, t_texture texture, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, texture.textures,
		(W_WIDTH - data->map_width * texture.width) / 2 + x * texture.width,
		(W_HEIGHT - data->map_height * texture.height)
		/ 2 + y * texture.height);
}

static void	print_elements_to_screen(t_game *data, int x, int y)
{
	if (data->map.map[y][x] == '1')
		draw_element(data, data->wall_texture, x, y);
	else if (data->map.map[y][x] == '0')
		draw_element(data, data->floor_texture, x, y);
	else if (data->map.map[y][x] == 'C')
		draw_element(data, data->coin_texture, x, y);
	else if (data->map.map[y][x] == 'P')
		draw_element(data, data->player_texture, x, y);
	else if (data->map.map[y][x] == 'E')
		draw_element(data, data->door_texture, x, y);
}
/*
void	free_map(t_game *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
}
*/

int	close_window(t_game *data)
{
	ft_double_pointer_free(data->map.map);
	exit(0);
}

void	print_map(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			print_elements_to_screen(data, x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		return (error(bad_args));
	check_map_extension(argv[1]);
	data.fd = open(argv[1], O_RDONLY);
	if (data.fd < 0)
		return (error(bad_args));
	data.map_height = count_lines(argv[1]);
	data.map.map = parse(&data);
	check_map_characters(&data, data.map_height, data.map_width);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "so_long");
	init_texture(&data);
	print_map(&data);
	mlx_hook(data.window, 17, 0, &close_window, &data);
	mlx_key_hook(data.window, &character_moves, &data);
	mlx_loop(data.mlx);
}
