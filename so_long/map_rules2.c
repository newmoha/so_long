/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:32:22 by maskour           #+#    #+#             */
/*   Updated: 2025/02/24 14:06:49 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *av)
{
	int		i;
	char	*storin;

	i = 0;
	storin = ft_strrchr(av, '.');
	if (!storin || ft_strncmp(storin, ".ber\0", 5) != 0)
		return (1);
	return (0);
}

int	check_rectanglar(t_game_mnag **data)
{
	int	len;
	int	i;

	if (!(*data)->map ||!(*data)->map[0])
		return (1);
	len = ft_strlen((*data)->map[0]);
	i = 1;
	while ((*data)->map[i])
	{
		if ((int)ft_strlen((*data)->map[i]) != len)
			return (1);
		i++;
	}
	(*data)->map_hight = i;
	(*data)->map_width = len;
	return (0);
}

static int	check_horizontal_walls(char **map, int last_row, int last_col)
{
	int	j;

	j = 0;
	while (j <= last_col)
	{
		if (map[0][j] != '1' || map[last_row][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

static int	check_vertical_walls(char **map, int last_row)
{
	int	i;
	int	line;
	int	last_col;

	i = 0;
	while (i <= last_row)
	{
		line = ft_strlen(map[i]);
		if (map[i][line - 1] == '\n')
		{
			map[i][line - 1] = '\0';
			last_col = ft_strlen(map[i]) - 1;
		}
		else
			last_col = line - 1;
		if (map[i][0] != '1' || map[i][last_col] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	last_row;
	int	last_col;

	if (!map || !map[0])
		return (1);
	last_row = 0;
	while (map[last_row])
		last_row++;
	last_row--;
	last_col = ft_strlen(map[0]) - 1;
	return (check_horizontal_walls(map, last_row, last_col) \
			|| check_vertical_walls(map, last_row));
}
