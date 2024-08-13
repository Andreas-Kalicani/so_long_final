/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:07:01 by akalican          #+#    #+#             */
/*   Updated: 2024/06/10 14:23:27 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "mlx.h"
#include "./libft/ft_printf/ft_printf.h"

void	draw_texture(t_game *data, int pos[2])
{
	if (data->map.map[pos[1]][pos[0]] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->door_texture.textures,
			(W_WIDTH - data->map_width * data->door_texture.width)
			/ 2 + (pos[0] * data->door_texture.width),
			(W_HEIGHT - data->map_height * data->door_texture.height)
			/ 2 + (pos[1] * data->door_texture.height));
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor_texture.textures,
			(W_WIDTH - data->map_width * data->floor_texture.width)
			/ 2 + (pos[0] * data->floor_texture.width),
			(W_HEIGHT - data->map_height * data->floor_texture.height)
			/ 2 + (pos[1] * data->floor_texture.height));
	}
}

void	check_coin(t_game *data)
{
	if (data->map.map[data->player.y][data->player.x] == 'C')
	{
		flood_fill(data, data->player.x, data->player.y, &data->map.coin_count);
	}
}

void	increment_and_display_moves(t_game *data)
{
	data->count_moves++;
	ft_printf("Moves: %d\n", data->count_moves);
}

/*
int	check_map_walls(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map_width)
	{
		if (data->map.map[0][x] != '1'
			|| data->map.map[data->map_height - 1][x] != '1')
			return (0);
			x++;
	}
		y = 1;
	while (y < data->map_height - 1)
	{
		if (data->map.map[y][0] != '1'
		|| data->map.map[y][data->map_width - 1] != '1')
			return (0);
			y++;
	}
	return (1);
}*/