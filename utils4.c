/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalican <akalican@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:03:17 by akalican          #+#    #+#             */
/*   Updated: 2024/06/04 18:30:15 by akalican         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	check_map_cell(t_game *data, int x, int y)
{
	char	**map_dup;

	if (data->map.map[y][x] == 'C' || data->map.map[y][x] == 'E')
	{
		map_dup = map_duplicate(data);
		if (check_coin_reach(data, map_dup, x, y) == 0)
		{
			write(1, "Error map_cell\n", 14);
			exit(1);
		}
		ft_double_pointer_free(map_dup);
	}
}

void	iterate_map(t_game *data)
{
	int	p[2];

	ft_memset(p, 0, sizeof(p));
	while (data->map.map[p[1]])
	{
		while (data->map.map[p[1]][p[0]])
		{
			check_map_cell(data, p[0], p[1]);
			p[0]++;
		}
		p[1]++;
		p[0] = 0;
	}
}

int	map_checker(t_game *data)
{
	if (data_map_coin_exit_check(data) == 0)
	{
		write(1, "Error map checker", 17);
		exit(1);
	}
	iterate_map(data);
	return (1);
}
