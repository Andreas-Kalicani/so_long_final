/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:50:34 by akalican          #+#    #+#             */
/*   Updated: 2024/06/10 14:22:33 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "so_long.h"
#include "libft/libft.h"
#include <stdio.h>

void	move_up(t_game *data)
{
	int	pos[2];
	int	count_c;

	if (data->map.map[data->player.y - 1] && data->player.y - 1 >= 0
		&& data->map.map[data->player.y - 1][data->player.x] != '1')
	{
		pos[0] = data->player.x;
		pos[1] = data->player.y;
		data->player.y -= 1;
		draw_texture(data, pos);
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures,
			(W_WIDTH - data->map_width * data->player_texture.width)
			/ 2 + (data->player.x * data->player_texture.width),
			(W_HEIGHT - data->map_height * data->player_texture.height)
			/ 2 + (data->player.y * data->player_texture.height));
		data->count_moves++;
		check_coin(data);
		count_c = data->map.coin_count;
		flood_fill(data, data->map_width, data->map_height, &count_c);
	}
}

void	move_down(t_game *data)
{
	int	pos[2];
	int	count_c;

	if (data->map.map[data->player.y + 1] && data->player.y
		+ 1 < data->map_height && data->map.map[data->player.y
			+ 1][data->player.x] != '1')
	{
		pos[0] = data->player.x;
		pos[1] = data->player.y;
		data->player.y += 1;
		draw_texture(data, pos);
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures,
			(W_WIDTH - data->map_width * data->player_texture.width)
			/ 2 + (data->player.x * data->player_texture.width),
			(W_HEIGHT - data->map_height * data->player_texture.height)
			/ 2 + (data->player.y * data->player_texture.height));
		data->count_moves++;
		check_coin(data);
		count_c = data->map.coin_count;
		flood_fill(data, data->map_width, data->map_height, &count_c);
	}
}

void	move_left(t_game *data)
{
	int	pos[2];
	int	count_c;

	if (data->map.map[data->player.y][data->player.x - 1] && data->player.x
		- 1 >= 0 && data->map.map[data->player.y][data->player.x - 1] != '1')
	{
		pos[0] = data->player.x;
		pos[1] = data->player.y;
		data->player.x -= 1;
		draw_texture(data, pos);
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures,
			(W_WIDTH - data->map_width * data->player_texture.width)
			/ 2 + (data->player.x * data->player_texture.width),
			(W_HEIGHT - data->map_height * data->player_texture.height)
			/ 2 + (data->player.y * data->player_texture.height));
		data->count_moves++;
		check_coin(data);
		count_c = data->map.coin_count;
		flood_fill(data, data->map_width, data->map_height, &count_c);
	}
}

void	move_right(t_game *data)
{
	int	pos[2];
	int	count_c;

	if (data->map.map[data->player.y][data->player.x + 1] && data->player.x
		+ 1 < data->map_width && data->map.map[data->player.y][data->player.x
		+ 1] != '1')
	{
		pos[0] = data->player.x;
		pos[1] = data->player.y;
		data->player.x += 1;
		draw_texture(data, pos);
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_texture.textures,
			(W_WIDTH - data->map_width * data->player_texture.width)
			/ 2 + (data->player.x * data->player_texture.width),
			(W_HEIGHT - data->map_height * data->player_texture.height)
			/ 2 + (data->player.y * data->player_texture.height));
		data->count_moves++;
		check_coin(data);
		count_c = data->map.coin_count;
		flood_fill(data, data->map_width, data->map_height, &count_c);
	}
}

int	character_moves(int key, t_game *data)
{
	if (key == w)
		move_up(data);
	if (key == s)
		move_down(data);
	if (key == a)
		move_left(data);
	if (key == d)
		move_right(data);
	if (key == ESC)
		destroy(data);
	if (data->map.coin_count == 0)
	{
		if (data->map.map[data->player.y][data->player.x] == 'E')
		{
			increment_and_display_moves(data);
			write(1, "game over!\n", 10);
			destroy(data);
		}
	}
	return (key);
}
