/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:47:34 by maskour           #+#    #+#             */
/*   Updated: 2025/02/27 16:22:05 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_game_mnag *game, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = x;
	map_y = y;
	if (map_x < 0 || map_x >= game->map_width \
		||map_y < 0 || map_y >= game->map_hight)
		return (0);
	if (game->map[map_y][map_x] == '1')
		return (0);
	if (game->map[map_y][map_x] == 'C')
	{
		game->map[y][x] = '0';
		mlx_put_image_to_window(game->mlx, game->win, \
			game->img_background, x * 48, y * 48);
		game->colleced_coins += 1;
	}
	if (game->map[map_y][map_x] == 'E')
		if (game->colleced_coins == game->found_collectable)
			(update_moves(game), exit_game(game, 0));
	update_moves(game);
	return (1);
}

void	go_up(t_game_mnag *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.x;
	new_y = game->player_pos.y - 1;
	if (check_move(game, new_x, new_y) == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_background, \
		game->player_pos.x * 48, game->player_pos.y * 48);
		if (game->map[game->player_pos.y][game->player_pos.x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit, \
			game->player_pos.x * 48, game->player_pos.y * 48);
		game->player_pos.x = new_x;
		game->player_pos.y = new_y;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->img_player, game->player_pos.x * 48, game->player_pos.y * 48);
	}
}

void	go_down(t_game_mnag *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.x;
	new_y = game->player_pos.y + 1;
	if (check_move(game, new_x, new_y) == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_background, \
			game->player_pos.x * 48, game->player_pos.y * 48);
		if (game->map[game->player_pos.y][game->player_pos.x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit, \
			game->player_pos.x * 48, game->player_pos.y * 48);
		game->player_pos.x = new_x;
		game->player_pos.y = new_y;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, \
		game->player_pos.x * 48, game->player_pos.y * 48);
	}
}

void	go_left(t_game_mnag *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.x - 1;
	new_y = game->player_pos.y;
	if (check_move(game, new_x, new_y) == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_background, \
			game->player_pos.x * 48, game->player_pos.y * 48);
		if (game->map[game->player_pos.y][game->player_pos.x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit, \
			game->player_pos.x * 48, game->player_pos.y * 48);
		game->player_pos.x = new_x;
		game->player_pos.y = new_y;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, \
		game->player_pos.x * 48, game->player_pos.y * 48);
	}
}

void	go_right(t_game_mnag *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_pos.x + 1;
	new_y = game->player_pos.y;
	if (check_move(game, new_x, new_y) == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_background, \
						game->player_pos.x * 48, game->player_pos.y * 48);
		if (game->map[game->player_pos.y][game->player_pos.x] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit, \
			game->player_pos.x * 48, game->player_pos.y * 48);
		game->player_pos.x = new_x;
		game->player_pos.y = new_y;
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, \
						game->player_pos.x * 48, game->player_pos.y * 48);
	}
}
