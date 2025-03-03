/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:34:10 by maskour           #+#    #+#             */
/*   Updated: 2025/02/24 11:53:33 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectables(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	flood_fill(char **tab, t_game_mnag *game, int x, int y)
{
	if (x < 0 || y < 0 || y >= game->map_hight || x >= game->map_width
		|| tab[y][x] == '1' || tab[y][x] == 'F')
		return ;
	if (tab[y][x] == 'E')
		game->found_exit = 1;
	else if (tab[y][x] == 'C')
		game->found_collectable += 1;
	tab[y][x] = 'F';
	flood_fill(tab, game, x + 1, y);
	flood_fill(tab, game, x - 1, y);
	flood_fill(tab, game, x, y + 1);
	flood_fill(tab, game, x, y - 1);
}

char	**copy_map(char **original, t_game_mnag *size)
{
	int		y;
	char	**copy;

	y = 0;
	copy = malloc(sizeof(char *) * (size->map_hight + 1));
	if (!copy)
		return (NULL);
	while (y < size->map_hight)
	{
		copy[y] = malloc(sizeof(char) * (size->map_width + 1));
		if (!copy[y])
		{
			while (--y >= 0)
				free(copy[y]);
			free(copy);
			return (NULL);
		}
		ft_memcpy(copy[y], original[y], size->map_width);
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

int	all_coins_collected(char **copied_map, t_game_mnag size)
{
	int	y;
	int	x;

	y = 0;
	while (y < size.map_hight)
	{
		x = 0;
		while (x < size.map_width)
		{
			if (copied_map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	can_reach_exit_and_coins(char **original_map, t_game_mnag *game)
{
	char	**copied_map;
	int		result;
	int		y;

	result = 1;
	y = 0;
	copied_map = copy_map(original_map, game);
	if (!copied_map)
		return (0);
	flood_fill(copied_map, game, game->player_pos.x, game->player_pos.y);
	if (game->found_collectable != count_collectables(original_map))
		result = 0;
	if (game->found_exit != 1)
		result = 0;
	y = 0;
	while (y < game->map_hight)
	{
		free(copied_map[y]);
		y++;
	}
	free(copied_map);
	return (result);
}
