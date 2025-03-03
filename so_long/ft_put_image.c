/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 05:12:17 by maskour           #+#    #+#             */
/*   Updated: 2025/02/27 16:20:24 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_moves(t_game_mnag *game)
{
	write(1, "Moves : ", 8);
	ft_putnbr_fd(++game->moves_counter, 1);
	write(1, "\n", 1);
}

static void	put_image(t_game_mnag *var, int x, int y, void *image)
{
	mlx_put_image_to_window((var)->mlx, (var)->win, image, x, y);
}

void	put_image_win(char p, int x, int y, t_game_mnag *var)
{
	if (p == '1')
		put_image(var, x, y, var->img_wall);
	else if (p == 'C')
	{
		put_image(var, x, y, var->img_background);
		put_image(var, x, y, var->img_collectable);
	}
	else if (p == 'E')
	{
		put_image(var, x, y, var->img_background);
		put_image(var, x, y, var->img_exit);
	}
	else if (p == 'P')
	{
		put_image(var, x, y, var->img_background);
		put_image(var, x, y, var->img_player);
	}
	else
		put_image(var, x, y, var->img_background);
}

void	game_tools(t_game_mnag *game_data)
{
	int	tile_size;
	int	x;
	int	y;
	int	x_map;
	int	y_map;

	y = 0;
	y_map = 0;
	tile_size = 48;
	while (game_data->map_hight > y_map)
	{
		x = 0;
		x_map = 0;
		while (game_data->map_width > x_map)
		{
			put_image_win(game_data->map[y_map][x_map], x, y, game_data);
			x_map++;
			x += tile_size;
		}
		y_map++;
		y += 48;
	}
}
