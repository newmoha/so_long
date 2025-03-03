/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:44:06 by maskour           #+#    #+#             */
/*   Updated: 2025/02/21 18:01:47 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_player_pos(t_game_mnag *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_hight)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_pos.x = x;
				game->player_pos.y = y;
				return ;
			}
		}
	}
}

int	check_charakters(char **map, char c, int max)
{
	int	i;
	int	count;
	int	j;

	if (!map || !map[0])
		return (1);
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	if (c == 'P' || c == 'E')
		return (count != max);
	else if (c == 'C')
		return (count < max);
	return (0);
}

int	check_valid_charakter(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E' \
						&& map[i][j] != '0' && map[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_map(t_game_mnag *data)
{
	if (!data->map || !data->map[0])
		return (1);
	if (check_rectanglar(&data))
		return (1);
	if (check_walls(data->map))
		return (1);
	if (check_charakters(data->map, 'P', 1))
		return (1);
	if (check_charakters(data->map, 'E', 1))
		return (1);
	if (check_charakters(data->map, 'C', 1))
		return (1);
	if (check_valid_charakter(data->map))
		return (1);
	init_player_pos(data);
	return (0);
}
